import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("rx-bench")
    RowLayout{
        anchors.fill: parent

        Bench{
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Results{
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width/3
        }
    }
}
