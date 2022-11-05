#include "pch.h"

#include "HalconBase.h"




CHalconBase::CHalconBase() {

	Start();

}

CHalconBase::~CHalconBase() {

	Stop();

}

void  CHalconBase::Snap(CString strSavePath) {


	CStringA strA(strSavePath + _T("Snap shot.jpg"));
	
	const char* strc = strA;

	
	//GrabImage(&ho_Image, hv_AcqHandle);

	WriteImage(ho_Image, "jpeg", 0, strc);

}



void CHalconBase::SetCam(int nSelect, int nVal) {

	HTuple hv_Parameter[eCamParam::eEndCamParam] = {
		 "brightness",
		 "contrast",
		 "saturation",
		 "sharpness",
		 "white_balance",
		 "frame_rate",
		 "zoom",
	};

	if (nSelect == eFramerate)	 return;


	SetFramegrabberParam(hv_AcqHandle, hv_Parameter[nSelect], nVal);
}


void CHalconBase::Start() {

	ho_Image.GenEmptyObj();

	OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "rgb", -1, "false",
		"default", "[0] ", 0, -1, &hv_AcqHandle);
	

	Sleep(1000);
}

void CHalconBase::Stop() {

	CloseFramegrabber(hv_AcqHandle);
}



void CHalconBase::Live() {

	GrabImage(&ho_Image, hv_AcqHandle);


	GetImageSize(ho_Image,
		&hv_Width,
		&hv_Height);

	DispColor(ho_Image,
		hv_WindowHandle);

	SetPart(hv_WindowHandle, 0, 0,
		hv_Height - 1, hv_Width - 1);
}



