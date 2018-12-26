import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Rectangle {
    //        color: "#97a85d"
    border.color: "grey"
    ListView{
        id:list
        width: parent.width
        anchors.margins: 10
        anchors.fill: parent
        model: rx.qresults
        delegate:  Item {
            width: parent.width
            height: 20
            RowLayout{
                Text { text: modelData.pos; Layout.minimumWidth: 40}
                Text { text: modelData.len; Layout.minimumWidth: 30}
                TextInput { text: modelData.result; Layout.fillWidth: parent; enabled: false }
            }

            MouseArea {
                anchors.fill: parent
                onClicked:{
                    list.currentIndex = index
                    rx.selectedIndex(index);
                }
            }
        }
        highlight: Rectangle {
            width: parent.width
            height: 20
            color: 'grey'
            x: list.currentItem.x;
            y: list.currentItem.y;
        }
        highlightFollowsCurrentItem: false
        focus: true
        onCurrentItemChanged: console.log(model[list.currentIndex].result)
    }
}
