#pragma once
#include <chrono>
#include <vector>
#include <thread>
#include "../sixcore.h"
namespace Engine{
	class SIXAPI STimer
	{
	public:
		void Update();
		void Init(bool& res);
		void Reset();
		void ResetCounter() {
			m_counter = 0;
		};
		int GetCounter() const {
			return m_counter;
		};
		void SetFPS(float fps) {
			m_setfps = fps;
		};
		static std::vector<int> GetNowTime();
	public:
		float deltatime = 0.1f;
		float nowtime = 0.f;
	private:
		float lasttime = 0.f;
		int m_counter = 0;
		float m_setfps = 60;
		float m_fps = 60;
		std::chrono::steady_clock::time_point m_start;
	};
}

