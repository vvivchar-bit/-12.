object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 440
  ClientWidth = 641
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Image1: TImage
    Left = 489
    Top = 8
    Width = 144
    Height = 169
    Center = True
    Proportional = True
    Stretch = True
    Visible = False
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 264
    Width = 641
    Height = 176
    Align = alBottom
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #1050#1086#1076
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1055#1088#1110#1079#1074#1080#1097#1077
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1030#1084#39#1103
        Width = 81
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1055#1086' '#1073#1072#1090#1100#1082#1086#1074#1110
        Width = 134
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1044#1072#1090#1072' '#1085#1072#1088#1086#1076#1078#1077#1085#1085#1103
        Width = 122
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1043#1088#1091#1087#1072
        Width = 43
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1060#1086#1090#1086#1075#1088#1072#1092#1110#1103
        Width = -1
        Visible = False
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 184
    Width = 300
    Height = 25
    DataSource = DataSource1
    TabOrder = 1
  end
  object Button1: TButton
    Left = 489
    Top = 183
    Width = 144
    Height = 25
    Caption = #1047#1072#1074#1072#1085#1090#1072#1078#1080#1090#1080' '#1092#1086#1090#1086
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 489
    Top = 214
    Width = 144
    Height = 25
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1092#1086#1090#1086
    TabOrder = 3
    OnClick = Button2Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\'#1058#1072#1073#1083#1080#1094#1110'\Students' +
      '.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 24
    Top = 32
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1057#1090#1091#1076#1077#1085#1090#1080
    Left = 24
    Top = 80
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 88
    Top = 80
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 88
    Top = 32
  end
end
