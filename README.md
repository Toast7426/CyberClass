### main
InfoDP主函数所在，包括窗口注册，消息循环，消息处理等
### display
BeginPaint至EndPaint，含窗口绘图显示的主逻辑函数
### read_ifs
大多为display中函数调用，读取课表文件、配置文件等
### date_time
使用WindowsAPI获取当前时间(日、时、分)
