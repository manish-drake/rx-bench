import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle {
    //    color: "#e86f33"
    ColumnLayout {
        anchors.fill: parent
        TextField {
            id: txtPattern
            placeholderText: qsTr("Pattern")
            anchors.leftMargin: 0
            Layout.fillWidth: true
            Keys.onReturnPressed: rx.run();
        }
        Binding {
            target: rx
            property: 'pattern'
            value: txtPattern.text
        }
        Binding {
            target: txtPattern
            property: 'text'
            value: rx.pattern
        }

        Rectangle {
            id: name
//            color: "#9faf59"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Flickable{
                id: flic
                anchors.fill: parent
                TextArea.flickable:  TextArea {
                    id: txtInput
                    placeholderText: qsTr("String Input")
                    text: "Corpus tests allow you to unit test your regular expressions using a typical red/green development flow.\nTest sections are marked indicating if the following lines should (#+) or should not (#-) match the regex pattern. Blank lines are ignored."
                    wrapMode: Text.WordWrap
                }
                ScrollBar.vertical: ScrollBar{ }
            }
        }

        Binding {
            target: rx
            property: 'input'
            value: txtInput.text
        }

        Button {
            id: btnRun
            text: qsTr("Run")
            Layout.fillWidth: true
            onClicked: rx.run()
        }
    }
}
