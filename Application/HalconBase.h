#pragma once


#include "HalconCpp.h"
#include "HDevEngineCpp.h"

#include"HalconBase_Info.h"

using namespace HalconCpp;


class CHalconBase {

public :

	CHalconBase();
	~CHalconBase();


public:
	HObject		ho_Image;					// Image
	HTuple		hv_WindowHandle;			// Halcon Window Handle
	HTuple		hv_AcqHandle;				// Halcon Webcam Handle

	HTuple		hv_Width, hv_Height;

	int			m_nArrCamParam[eCamParam::eEndCamParam];			// parameter of webcam
private:

	void Start();
	void Stop();

public:

	void SetCam(int nSelect, int nVal);

	void Snap(CString strSavePath);

	void Live();





};