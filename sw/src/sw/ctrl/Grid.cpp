#include "Grid.h"

namespace sw {
	namespace ctrl {

		const AttachedProperty<int> Grid::RowProperty = AttachedProperty<int>("Row", 0);
		const AttachedProperty<int> Grid::ColumnProperty = AttachedProperty<int>("Column", 0);

		Grid::Grid() :
			ContentListControl(), ControlBase() {
			ResizeEvent.addHandler([&](ControlBase::ResizeEventArgs args) {
				this->recalculateGrid();
				this->redraw();
			});
		}


		Grid::~Grid() {
		}

		void Grid::render() {
			if (!isRenderingSuspended()) {
				getParrent()->render();
			}
		}

		void Grid::drawOn(graph::Bitmap* target, util::Point offset) {
			for (ControlBase* child : getChildren()) {
				int row = RowProperty.getValue(
					static_cast<PropertyContainer*>(child));
				int col = ColumnProperty.getValue(
					static_cast<PropertyContainer*>(child));

				int offset_x = 0, offset_y = 0;
				for (int i = 0; i < col; i++) {
					offset_x += m_ColumnWidths[i];
				}
				for (int i = 0; i < row; i++) {
					offset_y += m_RowHeights[i];
				}

				util::Point cell = util::Point(offset_x, offset_y);

				child->drawOn(target, offset + cell);
			}
		}

		void Grid::resize() {
			LayoutControl::resize();

			suspendRendering();
			for (ControlBase* item : getChildren()) {
				item->resize();
			}
			resumeRendering();
			render();
		}

		util::Size Grid::getContainerArea(ControlBase* control) {
			int row = RowProperty.getValue(
				static_cast<PropertyContainer*>(control));
			int col = ColumnProperty.getValue(
				static_cast<PropertyContainer*>(control));
			return util::Size(m_RowHeights[row], m_ColumnWidths[col]);
		}

		void Grid::setGrid(const std::vector<int>& columns, const std::vector<int>& rows) {
			m_Columns = columns;
			m_Rows = rows;

			m_ColumnWidthSum = 0;
			for (int column : m_Columns) {
				m_ColumnWidthSum += column;
			}

			m_RowHeightSum = 0;
			for (int row : m_Rows) {
				m_RowHeightSum += row;
			}

			recalculateGrid();
		}

		void Grid::recalculateGrid() {
			m_ColumnWidths.clear();
			m_RowHeights.clear();

			util::Size size = getSize();

			for (int column : m_Columns) {
				m_ColumnWidths.push_back(column * size.w / m_ColumnWidthSum);
			}

			for (int row : m_Rows) {
				m_RowHeights.push_back(row * size.w / m_RowHeightSum);
			}
		}

		void Grid::addChild(ControlBase* child) {
			addToChildren(child);
		}
	}
}