#pragma once

#include "sw/util/Size.h"

namespace sw {

	class RenderTarget {
	public:
		virtual ~RenderTarget() = default;

		virtual void beginRender() = 0;
		virtual void endRender() = 0;

		virtual Size getSize() const = 0;
	};

}