#pragma once

#include "sw/util/Size.h"
#include "sw/util/Point.h"

namespace sw {

	class Renderer;

	class ControlBase;

	class ControlParrent {
	public:
		virtual ~ControlParrent() = default;
		virtual Size getContainerArea(ControlBase* control) const = 0;
		virtual Point transformToWindowSpace(Point point, const ControlBase* const control) const = 0;
		virtual Renderer* getRenderer() const = 0;

	};

}

#include "sw/Renderer.h"
#include "sw/ctrl/ControlBase.h"
