/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2013 - 2014 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_COOKIESCONTENTSWIDGET_H
#define OTTER_COOKIESCONTENTSWIDGET_H

#include "../../../ui/ContentsWidget.h"

#include <QtGui/QStandardItemModel>
#include <QtNetwork/QNetworkCookie>

namespace Otter
{

namespace Ui
{
	class CookiesContentsWidget;
}

class Window;

class CookiesContentsWidget : public ContentsWidget
{
	Q_OBJECT

public:
	explicit CookiesContentsWidget(Window *window);
	~CookiesContentsWidget();

	void print(QPrinter *printer);
	QAction* getAction(WindowAction action);
	QString getTitle() const;
	QLatin1String getType() const;
	QUrl getUrl() const;
	QIcon getIcon() const;
	bool isLoading() const;

public slots:
	void triggerAction(WindowAction action, bool checked = false);

protected:
	void changeEvent(QEvent *event);
	QStandardItem* findDomain(const QString &domain);
	QNetworkCookie getCookie(const QModelIndex &index) const;

protected slots:
	void triggerAction();
	void populateCookies();
	void filterCookies(const QString &filter);
	void addCookie(const QNetworkCookie &cookie);
	void removeCookie(const QNetworkCookie &cookie);
	void removeCookies();
	void removeDomainCookies();
	void showContextMenu(const QPoint &point);
	void updateActions();

private:
	QStandardItemModel *m_model;
	QHash<WindowAction, QAction*> m_actions;
	bool m_isLoading;
	Ui::CookiesContentsWidget *m_ui;
};

}

#endif
