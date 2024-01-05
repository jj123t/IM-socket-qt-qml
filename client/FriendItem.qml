// ChatItem.qml
import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    width: parent.width
    height: 20
    color: "lightblue"

    property string username: ""
    property int userid: 0
    RowLayout {
        anchors.fill: parent
        spacing: 5
        ColumnLayout {
            Text {
                text: username
                font.bold: true
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            customInfoModel.sendMessage("#" + String(customInfoModel.getMyId()) + "#" + String(userid));
        }
    }
}
