import QtQuick
import QtQml
import QtQuick.Controls
import QtQuick.Controls.Material
import Qt.labs.platform


Window {
    id: root
     width: 640
     height: 480
    visible: true
    title: qsTr("Hello World")


    Flickable
    {
         id: flickId

         width: root.width
         height: root.height * 0.7
         contentWidth: editId.contentWidth
         contentHeight: editId.contentHeight
         clip: true


         Rectangle
         {
             width: flickId.width
             height: flickId.height
             color: "black"
             border.color: "black"
             border.width: 1
             radius: 5

             TextEdit
             {
                id: editId
                width: flickId.width
                focus: true
                wrapMode: TextEdit.Wrap
                font.pointSize: 13
                color: "lightgreen"
                text: displayText;
                onTextChanged:
                {

                }

             }
         }
    }
    property string displayText: ""
    Connections
    {
        target: serverHandler
        function onMsgChanged() {
            displayText = serverHandler.msg + "\n" + editId.text;
        }
    }
}
