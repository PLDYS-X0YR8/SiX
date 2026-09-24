#pragma once
#ifdef SIX_EXPORT
	#define SIXAPI __declspec(dllexport)
#else
	#define SIXAPI __declspec(dllimport)
#endif