typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	mode;
		kal_uint32	reserved;
	} mmi_eq_usbconfig_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
		kal_uint8	mode;
		kal_uint32	reserved;
	} mmi_eq_usbconfig_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
	} mmi_eq_usbdetect_ind_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	app;
		UART_PORT	new_port;
	} mmi_eq_usbuart_switch_port_req_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_bool	result;
	} mmi_eq_usbuart_switch_port_rsp_struct;
	typedef struct
	{
		LOCAL_PARA_HDR
		kal_uint8	action;
	} mmi_eq_usbdetect_res_req_struct;