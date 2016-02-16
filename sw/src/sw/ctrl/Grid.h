#pragma once

#include "../graph/Bitmap.h"
#include "../util/Point.h"

#include "ContentListControl.h"
#include "LayoutControl.h"

namespace sw {
	namespace ctrl {

		class ControlBase;

		class Grid
			: public virtual ContentListControl,
			public virtual LayoutControl {
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
			virtual void drawOn(graph::Bitmap* target, util::Point offset);
			virtual void resize();

			virtual util::Size getContainerArea(ControlBase* control);

			void setGrid(const std::vector<int>& columns, const std::vector<int>& rows);

			void addChild(ControlBase* child);

		private:
			void recalculateGrid();
		};

	}
}