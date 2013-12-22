#ifndef OTTER_SEARCHWIDGET_H
#define OTTER_SEARCHWIDGET_H

#include <QtGui/QStandardItemModel>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCompleter>

namespace Otter
{

struct SearchSuggestion;

class SearchSuggester;

class SearchWidget : public QComboBox
{
	Q_OBJECT

public:
	explicit SearchWidget(QWidget *parent = NULL);

	QString getCurrentSearchEngine() const;

public slots:
	void setCurrentSearchEngine(const QString &engine);

protected slots:
	void optionChanged(const QString &option, const QVariant &value);
	void currentSearchChanged(int index);
	void queryChanged(const QString &query);
	void sendRequest(const QString &query = QString());
	void updateSearchEngines();
	void updateSuggestions(const QList<SearchSuggestion> &suggestions);

private:
	QStandardItemModel *m_model;
	QCompleter *m_completer;
	SearchSuggester *m_suggester;
	QString m_query;
	int m_index;

signals:
	void requestedSearch(QString query, QString engine);
};

}

#endif
