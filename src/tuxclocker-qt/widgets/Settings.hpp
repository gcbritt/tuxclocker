#pragma once

#include <optional>
#include <QVariant>
#include <QWidget>

class QCheckBox;
class QListWidget;

// TODO: duplicate definition
struct AssignableSetting {
	QString assignablePath;
	QVariant value;
};

struct SettingsData {
	bool autoApplyProfile;
	std::optional<QString> currentProfile;
	QVector<AssignableSetting> assignableSettings;
};

class Settings : public QWidget {
public:
	explicit Settings(QWidget *parent = nullptr);
signals:
	void cancelled();
	void settingsSaved(SettingsData);
private:
	SettingsData fromUIState();
	void writeSettings(SettingsData);

	QCheckBox *m_autoLoad;
	QCheckBox *m_useProfile;
	QListWidget *m_profileView;

	Q_OBJECT
};
