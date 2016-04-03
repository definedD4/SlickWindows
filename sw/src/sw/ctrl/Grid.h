#pragma once

#include "sw/Logger.h"
#include "sw/Common.h"

#include "../graph/Bitmap.h"
#include "../util/Point.h"

#include "ContentListControl.h"
#include "LayoutControl.h"

namespace sw {
	

		class ControlBase;

		class Grid
			: public virtual LayoutControl,
			public virtual LayoutControl_ {
		public:
			static const AttachedProperty<int> RowProperty, ColumnProperty;

		private:
			std::vector<int> m_Columns, m_Rows;
			std::vector<int> m_ColumnWidths, m_RowHeights;
			int m_ColumnWidthSum, m_RowHeightSum;

		public:
			Grid();
			~Grid();

			virtual void render();
			virtual void resize();

			virtual Size getContainerArea(ControlBase* control);

			void setGrid(const std::vector<int>& columns, const std::vector<int>& rows);

			void addChild(ControlBase* child);

		private:
			void recalculateGrid();
		};

	}
