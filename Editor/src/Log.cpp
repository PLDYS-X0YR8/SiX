#include "Log.h"

namespace SixEditor {
	void SELogWin::Render() {
		ImGui::Begin("Log", &m_open);
		static std::string filter;
		ImGui::SetNextItemWidth(-150.0f);
		ImGui::InputTextWithHint("##ContentFilter", "filter text", &filter);
		const char* items[] = {"Debug","Info","Error"};
		static int current_item = 0;
		ImGui::SameLine();
		ImGui::TextUnformatted("log type:");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(80.f);
		ImGui::Combo("##logType", &current_item, items, IM_ARRAYSIZE(items));
		ImGui::Separator();
		ImGui::End();
	}
}