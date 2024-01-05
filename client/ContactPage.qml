import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15
Item {
    signal toggleBottomBarVisibility(bool visible)

    ListView {
        id: listView
        anchors.fill: parent
        topMargin: 48
        leftMargin: 48
        bottomMargin: 48
        rightMargin: 48
        spacing: 20
        model: customInfoModel
        delegate: ChatItem {
            width: listView.width - listView.leftMargin - listView.rightMargin
            username: model.username
            text: "hello world"
            avatar: "qrc:/image.png"
        }
    }
}
