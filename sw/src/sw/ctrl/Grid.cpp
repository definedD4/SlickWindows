#include "Grid.h"

namespace sw {
	

		const AttachedProperty<int> Grid::RowProperty = AttachedProperty<int>("Row", 0);
		const AttachedProperty<int> Grid::ColumnProperty = AttachedProperty<int>("Column", 0);

		Grid::Grid() :
			LayoutControl(), ControlBase() {
		}


		Grid::~Grid() {
		}

		void Grid::render() {
			for (ControlBase* child : getChildren()) {
				child->render();
			}
		}

		void Grid::resize() {
			LayoutControl_::resize();

			recalculateGrid();

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

				Point pos = Point(offset_x, offset_y);
				setChildPosition(child, pos);
				child->resize();
			}

			render();
		}

		Size Grid::getContainerArea(ControlBase* control) {
			int row = RowProperty.getValue(
				static_cast<PropertyContainer*>(control));
			int col = ColumnProperty.getValue(
				static_cast<PropertyContainer*>(control));
			return Size(m_ColumnWidths[col], m_RowHeights[row]);
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

			Size size = getSize();

			for (int column : m_Columns) {
				m_ColumnWidths.push_back(column * size.w / m_ColumnWidthSum);
			}

			for (int row : m_Rows) {
				m_RowHeights.push_back(row * size.w / m_RowHeightSum);
			}
		}

		void Grid::addChild(ControlBase* child) {
			addChild(child);
		}
	}