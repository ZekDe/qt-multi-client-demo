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

// Window {
//     visible: true
//     width: 400
//     height: 600
//     title: "Search Example"

//     ListView {
//         id: searchResults
//         anchors.fill: parent
//         model: searchModel
//         delegate: Item {
//             width: parent.width
//             Text { text: displayText }
//         }
//     }

//     TextField {
//         id: searchField
//         width: parent.width
//         placeholderText: "Search for a place"
//         onTextChanged: {
//             // Arama işlevini çağırın
//             updateSearchResults(searchField.text)
//         }
//     }

//     ListModel {
//         id: searchModel
//         ListElement { displayText: "Ankara" }
//         ListElement { displayText: "İstanbul" }
//         ListElement { displayText: "İzmir" }
//     }

//     function updateSearchResults(text)
//     {
//          // Basit bir arama işlevi, gerçek bir arama işlevi ile değiştirilmelidir
//          searchModel.clear()
//          if (text.trim() === "")
//          {
//             return
//          }
//          for (var i = 0; i < initialResults.count; i++)
//          {
//              if (initialResults.get(i).toLowerCase().indexOf(text.toLowerCase()) !== -1)
//              {
//                  searchModel.append({ "displayText": initialResults.get(i) })
//              }
//          }
//      }

//     ListModel {
//         id: initialResults
//         ListElement { text: "Ankara" }
//         ListElement { text: "İstanbul" }
//         ListElement { text: "İzmir" }
//         ListElement { text: "Adana" }
//         ListElement { text: "Bursa" }
//         // Daha fazla örnek ekleyebilirsiniz
//     }
// }
