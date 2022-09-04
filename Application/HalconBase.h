#pragma once


#include "HalconCpp.h"
#include "HDevEngineCpp.h"

#include"HalconBase_Info.h"

using namespace HalconCpp;


class CHalconBase {

public :

	CHalconBase();
	~CHalconBase();

	UINT OpenCam();
	UINT Live();
	UINT Stop();
	
	void SetParam(int nSelect, int nVal);

	void GetErrCode(eErrorCode eErrorCode);


public:
	HObject		ho_Image;					// Image
	HTuple		hv_WindowHandle;			// Halcon Window Handle
	HTuple		hv_AcqHandle;				// Halcon Webcam Handle


	bool		m_bFlgBusy = false;			// Is port open ?

	int			m_nArrCamParam[eCamParam::eEndCamParam];			// parameter of webcam

};