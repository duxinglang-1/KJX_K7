
/* 资源在ROM中 */
/*
	3个参数分别表示：
	资源访问Cache的块大小，一般为0，（由于rom访问速度较快，不需要Cache）
	资源访问Cache的块数，一般为0
	资源地址
*/
/* Resource.irf */
TTSResPackMemSetItem(	0,	0,	g_NPR_ResData	)


/* 结束，此行不可修改 */
TTSResPackEndItem(	0,	0,	""	)
