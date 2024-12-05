#include "CarTableModel.h"
#include <QMessageBox>

CarTableModel::CarTableModel(QObject* parent) : QAbstractTableModel(parent) {};

QVariant CarTableModel::data(const QModelIndex& index, int role) const
{
	const int row = index.row();
	const int column = index.column();
	if (role == Qt::DisplayRole) 
	{
		switch (column)
		{
		case 0: return QString::fromStdString(carList.at(row).getLicensePlate());
		case 1: return QString::fromStdString(carList.at(row).getProducer());
		case 2: return QString::fromStdString(carList.at(row).getModel());
		case 3: return QString::fromStdString(carList.at(row).getType());

		}
		return QString("R%1, C%2").arg(index.row() + 1).arg(index.column() + 1);
	}
	return QVariant();

}

int CarTableModel::rowCount(const QModelIndex&) const noexcept
{
	return (int)(carList.size());
}
int CarTableModel::columnCount(const QModelIndex&) const noexcept
{
	return 4;
}

QVariant CarTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole) 
	{
		if (orientation == Qt::Horizontal) 
		{
			switch (section)
			{
			case 0: return QString("Numar inmatriculare");
			case 1: return QString("Producator");
			case 2: return QString("Model");
			case 3: return QString("Tip");

			}
			return QString("col %1").arg(section);
		}
		else {
			return QString("%1").arg(section);
		}
	}
	return QVariant();
}

void CarTableModel::setList(const vector<Car>& _carList)
{
	carList = _carList;
	const QModelIndex topLeft = createIndex(0, 0);
	const QModelIndex bottomRight = createIndex(rowCount(), columnCount());
	dataChanged(topLeft, bottomRight);
	layoutChanged();
}