#if !defined(AFX_BITMAPVIEWER_H__3A85192A_6B8B_4A76_B2CC_76604DCC2DB8__INCLUDED_)
#define AFX_BITMAPVIEWER_H__3A85192A_6B8B_4A76_B2CC_76604DCC2DB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BitmapViewer.h : header file
//


namespace MoDIS
{
    namespace MTE
    {
        //////////////////////////////////////////////////////////////////////
        // BitmapViewer window

        class Bitmap;
        class BitmapViewer : public CWnd
        {
        // Construction
        public:
            BitmapViewer();
            virtual ~BitmapViewer();

        private:
            BitmapViewer(const BitmapViewer &);
            BitmapViewer& operator=(const BitmapViewer &);

        public:
            void SetBitmap(Bitmap *bitmap);
            void ClearBitmap();

        // Overrides
            // ClassWizard generated virtual function overrides
            //{{AFX_VIRTUAL(BitmapViewer)
            //}}AFX_VIRTUAL

        protected:
            // Generated message map functions
            //{{AFX_MSG(BitmapViewer)
            afx_msg void OnPaint();
            afx_msg void OnLButtonDown(UINT flags, CPoint point);
            afx_msg void OnMouseMove(UINT flags, CPoint point);
            //}}AFX_MSG
            DECLARE_MESSAGE_MAP()

        private:
            bool RegisterWindowClass();
            bool IsHorizontallyDraggable();
            bool IsVerticallyDraggable();

        private:
            Bitmap *m_Bitmap;

            POINT m_DestCoordinate;
            POINT m_SrcCoordinate;
            int m_SrcWidth;
            int m_SrcHeight;

            CRect m_DisplayRect;
            CPoint m_LastPoint;
        };

        class Bitmap
        {
        public:
            Bitmap(char *bitmapBuffer, BITMAPINFOHEADER bitmapInfoHeader);
            Bitmap(const Bitmap &rhs);
            ~Bitmap();

        private:
            Bitmap& operator=(const Bitmap &);

        public:
            const char* GetBuffer() const;
            int GetWidth() const;
            int GetHeight() const;
            BITMAPINFOHEADER GetInfoHeader() const;
            int GetSize() const;

        private:
            char *m_Buffer;
            int m_Width;
            int m_Height;
            BITMAPINFOHEADER m_BitmapInfoHeader;
        };
    }
}

#endif // !defined(AFX_BITMAPVIEWER_H__3A85192A_6B8B_4A76_B2CC_76604DCC2DB8__INCLUDED_)
