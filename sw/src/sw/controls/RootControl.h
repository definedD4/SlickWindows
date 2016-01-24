#pragma once

#include "ControlBase.h"
#include "../Window.h"

namespace sw { namespace controls {
	
	class RootControl : virtual ControlBase {
	private:
		ControlBase* m_Child;
		Window* m_Owner;

	public:
		RootControl(Window* owner, ControlBase* child);
		~RootControl();
		
		void render() override;
		void resize() override;
		void redraw() override;
	};

} }
