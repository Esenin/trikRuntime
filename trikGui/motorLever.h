/* Copyright 2014 Roman Kurbatov
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#pragma once

#include <QtCore/qglobal.h>

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
	#include <QtGui/QWidget>
	#include <QtGui/QVBoxLayout>
	#include <QtGui/QLabel>
	#include <QtGui/QProgressBar>
#else
	#include <QtWidgets/QWidget>
	#include <QtWidgets/QVBoxLayout>
	#include <QtWidgets/QLabel>
	#include <QtWidgets/QProgressBar>
#endif

#include <QtCore/QString>

namespace trikControl {
	class Motor;
}

namespace trikGui {

/// Widget that allows to set power value of a motor and turn it on and off.
/// It is designed to use as a part of MotorsWidget.
class MotorLever : public QWidget
{
	Q_OBJECT

public:
	/// Constructor.
	/// @param port - name of a port which the motor is connected to.
	/// @param motor - pointer to an instance representing the motor.
	/// @param parent - pointer to a parent widget.
	MotorLever(QString const &port, trikControl::Motor &motor, QWidget *parent = 0);

	/// Destructor.
	~MotorLever();

protected:
	void keyPressEvent(QKeyEvent *event);
	void paintEvent(QPaintEvent *);

private:
	void setPower(int power);
	void turnOnOff();

	trikControl::Motor &mMotor;
	bool mIsOn;
	int const mMaxPower;
	int const mMinPower;
	int const mPowerStep;
	int mPower;

	QVBoxLayout mLayout;
	QLabel mNameLabel;
	QProgressBar mPowerBar;
	QLabel mPowerLabel;
	QLabel mOnOffLabel;
};

}
