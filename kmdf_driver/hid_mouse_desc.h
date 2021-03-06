/// by fanxiushu 2017-10-20 
//鼠标HID描述符, 两个按键（左，右）， 滚轮（水平滚动和垂直滚动）, X,Y采用相对值
#pragma once

#define REPORTID_MOUSE  2

/////
const unsigned char MouseReportDescriptor[] = {
	///
	0x05, 0x01, // USAGE_PAGE(Generic Desktop)
	0x09, 0x02, //   USAGE(Mouse)
	0xA1, 0x01, //   COLLECTION(APPlication)
	0x09, 0x01, //   USAGE(Pointer)
	0xA1, 0x00, //     COLLECTION(Physical)
	0x85, REPORTID_MOUSE, //     ReportID(Mouse ReportID)
	0x05, 0x09, //     USAGE_PAGE(Button)
	0x19, 0x01, //     USAGE_MINIMUM(button 1)   button 按键， 位 0 左键， 位1 右键
	0x29, 0x02, //     USAGE_MAXMUM(button 2)
	0x15, 0x00, //     LOGICAL_MINIMUM(0)
	0x25, 0x01, //     LOGICAL_MAXIMUM(1)
	0x95, 0x02, //     REPORT_COUNT(2)
	0x75, 0x01, //     REPORT_SIZE(1)
	0x81, 0x02, //     INPUT(Data,Var,Abs)
	0x95, 0x01, //     REPORT_COUNT(1)
	0x75, 0x06, //     REPORT_SIZE(6)
	0x81, 0x03, //     INPUT(Data,Var, Abs)
	0x05, 0x01, //     USAGE_PAGE(Generic Desktop)
	0x09, 0x30, //     USAGE(X)       X移动
	0x09, 0x31, //     USAGE(Y)       Y移动
	0x09, 0x38, //     USAGE(Wheel)   垂直滚动
	0x15, 0x81, //     LOGICAL_MINIMUM(-127)
	0x25, 0x7F, //     LOGICAL_MAXIMUM(127)
	0x75, 0x08, //     REPORT_SIZE(8)
	0x95, 0x03, //     REPORT_COUNT(3)
	0x81, 0x06, //     INPUT(Data,Var, Rel) //X,Y,垂直滚轮三个参数， 相对值

	//下边水平滚动
	0x05, 0x0C, //     USAGE_PAGE (Consumer Devices)
	0x0A, 0x38, 0x02, // USAGE(AC Pan)
	0x15, 0x81, //       LOGICAL_MINIMUM(-127)
	0x25, 0x7F, //       LOGICAL_MAXIMUM(127)
	0x75, 0x08, //       REPORT_SIZE(8)
	0x95, 0x01, //       REPORT_COUNT(1)
	0x81, 0x06, //       INPUT(data,Var, Rel) //水平滚轮，相对值
	0xC0,       //       End Connection(PhySical)
	0xC0,       //     End Connection

	/////////////

};

CONST HID_DESCRIPTOR DefaultHidDescriptor = {
	0x09,   // length of HID descriptor
	0x21,   // descriptor type == HID  0x21
	0x0100, // hid spec release
	0x00,   // country code == Not Specified
	0x01,   // number of HID class descriptors
	{ 0x22,   // descriptor type 
	sizeof(MouseReportDescriptor) }  // total length of report descriptor
};


///鼠标状态报告,对应的HID是上边的报告
#pragma pack(1)
struct mouse_report_t
{
	BYTE    report_id;
	BYTE    button; //0 no press, 1 left, 2 right ; 3 左右同时按下，触摸板一般不会有这种事
	CHAR    dx;
	CHAR    dy;
	CHAR    v_wheel; // 垂直
	CHAR    h_wheel; // 水平
};
#pragma pack()

