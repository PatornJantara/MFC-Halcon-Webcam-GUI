#pragma once


enum eGetImage {

	eFile	= 0	,
	eUsbCam		,

	eEndGetImage	,
};


enum eErrorCode {

	eNoErr	= 0,
	eErrNoFile	,
	eErrConnect	,



	eEndErrorCode,
};

enum MIN_MAX {
	eMin = 0,
	eMax = 1,
	eMIN_MAX,
};

// Webcam Hikvision U02-36
enum eCamParam {

	eBrightness  = 0 ,	// 1- 255
	eConstrast		,	// 1-255
	eSaturation		,	// 10-200
	eSharpness		,	// 1-255
	eWhiteBalance	,	// 2800-6500
	eFramerate		,	// 30
	eZoom			,	// 1-150

	eEndCamParam
};

const int CAM_PROP[eEndCamParam][eMIN_MAX]{

	{1,255},
	{1,255},
	{10,200},
	{1,255},
	{2800 , 6500},
	{30,30},
	{1,50},

};

const int CAM_PROP_DEFAULT[eEndCamParam]{

	100,
	100,
	100,
	90,
	4500,
	30,
	30,
};