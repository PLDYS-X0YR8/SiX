#pragma once
#ifdef SIX_EXPORT
	#define SIXAPI __declspec(dllexport)
#else
	#define SIXAPI __declspec(dllimport)
#endif

#define SELF_ADD_ID(cc) \
	public: \
		static size_t GetStaticTypeId() { return StaticTypeId<cc>(); } \
		virtual size_t GetTypeId() const override { return GetStaticTypeId(); }