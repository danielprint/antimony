#ifndef EXTRUDE_CONTROL_H
#define EXTRUDE_CONTROL_H

#include "control/control.h"
#include "control/wireframe.h"

class _ExtrudeSpanControl : public WireframeControl
{
public:
    explicit _ExtrudeSpanControl(Canvas* canvas, Node* node, QGraphicsItem* parent);
    QVector<QVector<QVector3D>> lines() const override;
    void drag(QVector3D center, QVector3D delta) override;
protected:
    QColor defaultPenColor() const override;
};

class ExtrudeControl : public WireframeControl
{
public:
    explicit ExtrudeControl(Canvas* canvas, Node* node);
    QVector<QVector<QVector3D>> lines() const override;
    void drag(QVector3D center, QVector3D delta) override;
    QPointF inspectorPosition() const override;
protected:
    QColor defaultPenColor() const override;
    _ExtrudeSpanControl* span;
};

#endif