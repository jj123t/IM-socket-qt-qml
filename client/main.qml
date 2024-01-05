import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
Window {
    id: window; width: 540; height: 540; visible: true
    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: homePage
        Component {
            id: homePage
            ContactPage {}
        }
        Component {
            id: aboutPage
            ContactList {}
        }
        Component {
            id: contactPage
            ContactTrend {}
        }
    }
    RowLayout {
        id: bottomBar; width: parent.width; height: 50
        anchors.bottom: parent.bottom
        property bool setButtomVisble: true
        visible: setButtomVisble
        Button {
            text: "Home"
            onClicked: stackView.push(homePage)
            Layout.alignment: Qt.AlignHCenter
        }
        Button {
            text: "About"
            onClicked: stackView.push(aboutPage)
            Layout.alignment: Qt.AlignHCenter
        }
        Button {
            text: "Contact"
            onClicked: stackView.push(contactPage)
            Layout.alignment: Qt.AlignHCenter
        }
    }
    Connections {
        target: stackView.currentItem
        ignoreUnknownSignals: true
        function onToggleBottomBarVisibility(visible) {
            bottomBar.visible = visible;
        }
    }
}

