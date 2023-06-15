import QtQuick
import QtQuick.Controls
import BigintLogic 1.0

Window {
    width: 400
    height: 250
    visible: true
    title: qsTr("Bigint calculator")


    BigintLogic {
        id: bigintLogic
    }

    Column {
        anchors.fill: parent

        spacing: 4
        padding: 8

        Label {
            text: "Bigint calculator 🖩"

            font.pointSize: 16
            font.bold: true
        }

        TextField {
            id: firstOperandTextField

            padding: 8
            font.pointSize: 12

            anchors.leftMargin: 8
            anchors.rightMargin: 8


            anchors.left: parent.left
            anchors.right: parent.right
            placeholderText: qsTr("Первый операнд")
        }

        TextField {
            id: secondOperandTextField

            padding: 8
            font.pointSize: 12

            anchors.leftMargin: 8
            anchors.rightMargin: 8

            anchors.left: parent.left
            anchors.right: parent.right
            placeholderText: qsTr("Второй операнд")
        }

        Row {
            id: buttonsRow

            spacing: 4

            anchors.leftMargin: 8
            anchors.rightMargin: 8

            anchors.left: parent.left
            anchors.right: parent.right

            RoundButton {
                id: sumButton
                text: "+"

                anchors.margins: 8

                onClicked: {
                    sumButton.enabled = false
                    substractButton.enabled = false

                    bigintLogic.add(firstOperandTextField.text, secondOperandTextField.text)
                }
            }

            RoundButton {
                id: substractButton
                text: "-"

                anchors.margins: 8

                onClicked: {
                    sumButton.enabled = false
                    substractButton.enabled = false

                    bigintLogic.substract(firstOperandTextField.text, secondOperandTextField.text)
                }
            }
        }


        TextField {
            id: bigintResultTextField

            padding: 8
            font.pointSize: 12

            anchors.leftMargin: 8
            anchors.rightMargin: 8

            anchors.left: parent.left
            anchors.right: parent.right
            placeholderText: qsTr("Результат Bigint")
            readOnly: true
        }

        Label {
            text: 'https://github.com/tastydata0/BigintGUI\nhttps://github.com/tastydata0/libBigint'
            color: "gray"
        }
    }

    Connections {
        target: bigintLogic

        function onCalculationSuccessful(res) {
            bigintResultTextField.text = res
            bigintResultTextField.color = "black"

            sumButton.enabled = true
            substractButton.enabled = true
        }

        function onCalculationError(res) {
            bigintResultTextField.text = res
            bigintResultTextField.color = "red"

            sumButton.enabled = true
            substractButton.enabled = true
        }
    }
}
