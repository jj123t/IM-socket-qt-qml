import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

Page {
    id: root

    property string username
    property var id

    signal toggleBottomBarVisibility(bool visible)

    header: ToolBar {
        ToolButton {
            text: qsTr("Back")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                toggleBottomBarVisibility(!bottomBar.visible);
                root.StackView.view.pop()
            }
        }
        Label {
            id: pageTitle
            text: username
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }
    ColumnLayout {
        anchors.fill: parent

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: pane.leftPadding + messageField.leftPadding
            displayMarginBeginning: 40
            displayMarginEnd: 40
            spacing: 12
            model: customInfoModel.getCustomModel(id);
            delegate: Row {
                property int rowIndex: model.rows - index - 1
                property int sender: model.sender
                anchors.right: sender ? listView.contentItem.right : undefined // 设置左右
                spacing: 6

                Rectangle {
                    id: avatar
                    width: height
                    height: parent.height
                    color: "grey"
                    visible: !sender
                }

                Rectangle {
                    width: 80
                    height: 40
                    color: sender ? "lightgrey" : "steelblue"
                    radius: 4
                    TalkLabel {
                        anchors.centerIn: parent
                        text: model.messageText
                        color: sender ? "black" : "white"
                    }
                }
            }
            ScrollBar.vertical: ScrollBar {}
        }

        Pane {
            id: pane
            Layout.fillWidth: true
//            model: customMessageModel.getCustomModel(id);
            RowLayout {
                width: parent.width
                TextArea {
                    id: messageField
                    Layout.fillWidth: true
                    placeholderText: qsTr("Compose message")
                    wrapMode: TextArea.Wrap
                }

                Button {
                    id: sendButton
                    text: qsTr("Send")
                    enabled: messageField.length > 0
                    onClicked: {
                        customInfoModel.addMessage(id, "@1" + messageField.text);
                        customInfoModel.sendMessage("@" + String(customInfoModel.getMyId()) + "#" + String(id) + "#" + messageField.text);
                        messageField.text = "";  // Clear the input field
                    }
                }
            }
        }
    }
}
