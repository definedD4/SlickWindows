#pragma once

#include "ControlBase.h"
#include "../Window.h"
#include "ContainerControl.h"

namespace sw { namespace controls {
	
	class RootControl : public virtual ControlBase, public virtual ContainerControl {
	private:
		ControlBase* m_Child;
		Window* m_Owner;

	public:
		RootControl(Window* owner, ControlBase* child);
		~RootControl();
		
		void render() override;
		void resize() override;
		void redraw() override;

		virtual util::Size getContainerArea(ControlBase* control) override;
	};

} }
