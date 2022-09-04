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