#ifndef BASICBLOCK_WIDGET_HH
#define BASICBLOCK_WIDGET_HH

#include <QGraphicsObject>
#include <QGraphicsSimpleTextItem>
#include <QModelIndex>
#include <QAbstractItemModel>

class BasicBlockWidget;
class MnemonicWidget;
class ControlTransferWidget;

class BasicBlockWidget : public QGraphicsObject
{
	Q_OBJECT

public:
	BasicBlockWidget(QModelIndex i, QGraphicsItem *parent = 0);
	
	virtual QRectF boundingRect(void) const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

protected:
//	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
	QVector<MnemonicWidget *> m_mnemonics;
	const QAbstractItemModel *m_model;
	QPersistentModelIndex m_root;
};

class MnemonicWidget : public QGraphicsItem
{
public:
	MnemonicWidget(QModelIndex i, QGraphicsItem *parent = 0);
	
	void setIdent(double s);
	double ident(void) const;

	virtual QRectF boundingRect(void) const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
	QGraphicsSimpleTextItem m_mnemonic;
	QVector<QGraphicsSimpleTextItem *> m_operands;
	double m_ident;
};


class ControlTransferWidget : public QGraphicsObject
{
	Q_OBJECT

public:
	ControlTransferWidget(const BasicBlockWidget &from, const BasicBlockWidget &to, QGraphicsItem *parent = 0);
};

#endif