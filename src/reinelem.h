

#ifndef _REINELEM_H_
#define _REINELEM_H_


/// <summary>
/// образующий элемент
/// </summary>
typedef struct reinelement
{
	reinelement();

	void clear();

	ReinSpace rs;
	ReinData rd;
	UInt32 fpRS; // file position
	ELID idRS;
	DgnModelRefP  modelRef;
	int iLevelMask;

	map<int, BarOver> mapOvers;

	int calcSurfRevolution(
								MSElementDescr *pedBar, 					// [ IN] // pointer on elem descriptor of boundary profile (bar)
								DPoint3d *pCentSurf, 						// [ IN] // центр окружности закругления surface-а
								double surfSwan, 							// [ IN] // sweep angle // in radian // угол развертки suface, радианная мера surface-а
								vector<ReinBar> &bars,						// [OUT] // ссылка на контейнер стержней
								DgnModelRefP mrP,							// [ IN] // model reference
								DVec3d *pAxis								// [ IN] // suface axis
						  );

} ReinElement;



#endif