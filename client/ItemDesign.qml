import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15
Item {
    property string username: ""
    property string text: ""
    property string avatar: ""

    signal onClicked()

    Rectangle {
        width: parent.width
        height: 100
        color: "lightblue"

        RowLayout {
            anchors.fill: parent
            spacing: 10

            Image {
                width: 50
                height: 50
                source: avatar
            }

            ColumnLayout {
                Text {
                    text: username
                    font.bold: true
                }

                Text {
                    text: text
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                onClicked();
            }
        }
    }
}
