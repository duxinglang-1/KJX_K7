// BitmapViewer.cpp : implementation file
// 

#include "StdAfx.h"
#include "BitmapViewer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static LPCTSTR BITMAPVIEWER_CLASSNAME  = _T("MoDIS_MTE_BitmapViewerCtrl");


using namespace MoDIS::MTE;

/////////////////////////////////////////////////////////////////////////////
// BitmapViewer

BitmapViewer::BitmapViewer()
    : m_Bitmap(NULL),
      m_DestCoordinate(),
      m_SrcCoordinate(),
      m_SrcWidth(0),
      m_SrcHeight(0),
      m_DisplayRect(0, 0, 0, 0),
      m_LastPoint(0, 0)
{
    RegisterWindowClass();
}

BitmapViewer::~BitmapViewer()
{
    ClearBitmap();
}

void BitmapViewer::SetBitmap(Bitmap *bitmap)
{
    ClearBitmap();
    m_Bitmap = bitmap;

    GetClientRect(&m_DisplayRect);
    m_SrcCoordinate.x = 0;

    if (m_Bitmap->GetWidth() > m_DisplayRect.Width())
    {
        m_DestCoordinate.x = m_DisplayRect.left;
        m_SrcWidth         = m_DisplayRect.Width();
    }
    else
    {
        m_DestCoordinate.x =
                m_DisplayRect.CenterPoint().x - (m_Bitmap->GetWidth()/2);
        m_SrcWidth = m_Bitmap->GetWidth();
    }

    if (m_Bitmap->GetHeight() > m_DisplayRect.Height())
    {
        m_DestCoordinate.y = m_DisplayRect.top;
        m_SrcHeight        = m_DisplayRect.Height();
        m_SrcCoordinate.y  = m_Bitmap->GetHeight() - m_DisplayRect.Height();
    }
    else
    {
        m_DestCoordinate.y =
                m_DisplayRect.CenterPoint().y - (m_Bitmap->GetHeight()/2);
        m_SrcHeight        = m_Bitmap->GetHeight();
        m_SrcCoordinate.y  = 0;
    }
}

void BitmapViewer::ClearBitmap()
{
    if (m_Bitmap != NULL)
    {
        delete m_Bitmap;
        m_Bitmap = NULL;
    }
}

BEGIN_MESSAGE_MAP(BitmapViewer, CWnd)
	//{{AFX_MSG_MAP(BitmapViewer)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BitmapViewer message handlers

void BitmapViewer::OnPaint()
{
    CPaintDC dc(this);

    if ((m_Bitmap != NULL) && (m_Bitmap->GetBuffer() != NULL))
    {
        ::SetDIBitsToDevice(
            dc.GetSafeHdc(),
            m_DestCoordinate.x,
            m_DestCoordinate.y,
            m_SrcWidth,
            m_SrcHeight,
            m_SrcCoordinate.x,
            m_SrcCoordinate.y,
            0,
            m_Bitmap->GetHeight(),
            m_Bitmap->GetBuffer(),
            reinterpret_cast<BITMAPINFO *>(&m_Bitmap->GetInfoHeader()),
            DIB_RGB_COLORS
        );
    }
}

void BitmapViewer::OnLButtonDown(UINT flags, CPoint point)
{
    if (!IsHorizontallyDraggable() && !IsVerticallyDraggable())
    {
        return;
    }

    m_LastPoint = point;
}

void BitmapViewer::OnMouseMove(UINT flags, CPoint point)
{
    if (!IsHorizontallyDraggable() && !IsVerticallyDraggable())
    {
        return;
    }

	::SetCursor(LoadCursor(0, MAKEINTRESOURCE(32649)));
    if (flags & MK_LBUTTON)
    {
        CSize offset(point - m_LastPoint);

        if (IsHorizontallyDraggable())
        {
            m_SrcCoordinate.x -= offset.cx;

            if (m_SrcCoordinate.x < 0)
            {
                m_SrcCoordinate.x = 0;
            }
            else if (m_SrcCoordinate.x >
                     (m_Bitmap->GetWidth() - m_DisplayRect.Width()))
            {
                m_SrcCoordinate.x =
                        m_Bitmap->GetWidth() - m_DisplayRect.Width();
            }
        }

        if (IsVerticallyDraggable())
        {
            m_SrcCoordinate.y += offset.cy;

            if (m_SrcCoordinate.y < 0)
            {
                m_SrcCoordinate.y = 0;
            }
            else if (m_SrcCoordinate.y >
                     (m_Bitmap->GetHeight() - m_DisplayRect.Height()))
            {
                m_SrcCoordinate.y =
                        m_Bitmap->GetHeight() - m_DisplayRect.Height();
            }
        }

        m_LastPoint = point;
        Invalidate(FALSE);
    }
}

bool BitmapViewer::IsHorizontallyDraggable()
{
    return (m_Bitmap != NULL) &&
           (m_Bitmap->GetWidth() > m_DisplayRect.Width());
}

bool BitmapViewer::IsVerticallyDraggable()
{
    return (m_Bitmap != NULL) &&
           (m_Bitmap->GetHeight() > m_DisplayRect.Height());
}

bool BitmapViewer::RegisterWindowClass()
{
    WNDCLASS windowClass;
    HINSTANCE appInstHandle = ::AfxGetInstanceHandle();

    if (!(::GetClassInfo(appInstHandle, BITMAPVIEWER_CLASSNAME, &windowClass)))
    {
        windowClass.style         = CS_HREDRAW | CS_VREDRAW;
        windowClass.lpfnWndProc   = ::DefWindowProc;
        windowClass.cbClsExtra    = 0;
        windowClass.cbWndExtra    = 0;
        windowClass.hInstance     = appInstHandle;
        windowClass.hIcon         = NULL;
        windowClass.hCursor       = NULL;
        windowClass.hbrBackground = (HBRUSH) (COLOR_3DFACE + 1);
        windowClass.lpszMenuName  = NULL;
        windowClass.lpszClassName = BITMAPVIEWER_CLASSNAME;

        if (!::AfxRegisterClass(&windowClass))
        {
            AfxThrowResourceException();
            return false;
        }
    }

    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Bitmap

Bitmap::Bitmap(char *bitmapBuffer, BITMAPINFOHEADER bitmapInfoHeader)
    : m_Buffer(bitmapBuffer),
      m_Width(bitmapInfoHeader.biWidth),
      m_Height(::abs(bitmapInfoHeader.biHeight)),
      m_BitmapInfoHeader(bitmapInfoHeader)
{
    // We only support ARGB8888 now
    ASSERT(m_BitmapInfoHeader.biBitCount == 32);
}

Bitmap::Bitmap(const Bitmap &rhs)
    : m_Buffer(NULL),
      m_Width(rhs.GetWidth()),
      m_Height(rhs.GetHeight()),
      m_BitmapInfoHeader(rhs.GetInfoHeader())
{
    m_Buffer = new char[rhs.GetSize()];
    ASSERT(m_Buffer != NULL);

    ::memcpy(m_Buffer, rhs.GetBuffer(), rhs.GetSize());
}

Bitmap::~Bitmap()
{
    if (m_Buffer != NULL)
    {
        delete [] m_Buffer;
    }
}

const char* Bitmap::GetBuffer() const
{
    return m_Buffer;
}

int Bitmap::GetWidth() const
{
    return m_BitmapInfoHeader.biWidth;
}

int Bitmap::GetHeight() const
{
    return ::abs(m_BitmapInfoHeader.biHeight);
}

BITMAPINFOHEADER Bitmap::GetInfoHeader() const
{
    return m_BitmapInfoHeader;
}

int Bitmap::GetSize() const
{
    return GetWidth() * GetHeight() * 4;
}
