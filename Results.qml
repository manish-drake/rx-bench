import QtQuick 2.7
import QtQuick.Controls 2.0

Rectangle {
//        color: "#97a85d"
    border.color: "grey"
    ListView{
        anchors.margins: 10
        anchors.fill: parent
        model: rx.qresults
        delegate:  Rectangle {
            width: parent.width
            height: 20
            Text { text: modelData.result }
        }
    }
}
