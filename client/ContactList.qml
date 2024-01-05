import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15
Item {
    ListView {
        id: contactlistView
        anchors.fill: parent
        topMargin: 48
        leftMargin: 48
        bottomMargin: 48
        rightMargin: 48
        spacing: 20
        model: customInfoModel
        delegate: FriendItem {
            width: contactlistView.width - contactlistView.leftMargin - contactlistView.rightMargin
            username: model.username
            userid: model.id
        }
    }
}
