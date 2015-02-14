object MainFrm: TMainFrm
  Left = 36
  Top = 122
  Width = 694
  Height = 466
  Caption = 'MainFrm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 528
    Top = 0
    Width = 158
    Height = 420
    Align = alRight
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 6
      Top = 8
      Width = 28
      Height = 13
      Caption = 'Offset'
    end
    object Label2: TLabel
      Left = 122
      Top = 8
      Width = 6
      Height = 13
      Caption = 'h'
    end
    object Label3: TLabel
      Left = 6
      Top = 30
      Width = 22
      Height = 13
      Caption = 'Step'
    end
    object Label5: TLabel
      Left = 6
      Top = 52
      Width = 44
      Height = 13
      Caption = 'Colonnes'
    end
    object Label7: TLabel
      Left = 6
      Top = 74
      Width = 43
      Height = 13
      Caption = 'Précision'
    end
    object Label4: TLabel
      Left = 6
      Top = 199
      Width = 39
      Height = 13
      Caption = 'Contrast'
    end
    object lblContrast: TLabel
      Left = 59
      Top = 199
      Width = 12
      Height = 13
      Caption = '50'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object edtOffset: TEdit
      Left = 60
      Top = 5
      Width = 60
      Height = 21
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      TabOrder = 0
      Text = '0'
      OnExit = edtOffsetExit
    end
    object sbOffset: TCSpinButton
      Left = 137
      Top = 5
      Width = 15
      Height = 21
      DownGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000008080000080800000808000000000000080800000808000008080000080
        8000008080000080800000808000000000000000000000000000008080000080
        8000008080000080800000808000000000000000000000000000000000000000
        0000008080000080800000808000000000000000000000000000000000000000
        0000000000000000000000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      TabOrder = 1
      UpGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000000000000000000000000000000000000000000000000000000000000080
        8000008080000080800000000000000000000000000000000000000000000080
        8000008080000080800000808000008080000000000000000000000000000080
        8000008080000080800000808000008080000080800000808000000000000080
        8000008080000080800000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      OnDownClick = sbOffsetDownClick
      OnUpClick = sbOffsetUpClick
    end
    object edtIncrement: TEdit
      Left = 60
      Top = 27
      Width = 60
      Height = 21
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      TabOrder = 2
      Text = '1'
      OnExit = edtIncrementExit
    end
    object sbIncrement: TCSpinButton
      Left = 137
      Top = 27
      Width = 15
      Height = 21
      DownGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000008080000080800000808000000000000080800000808000008080000080
        8000008080000080800000808000000000000000000000000000008080000080
        8000008080000080800000808000000000000000000000000000000000000000
        0000008080000080800000808000000000000000000000000000000000000000
        0000000000000000000000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      TabOrder = 3
      UpGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000000000000000000000000000000000000000000000000000000000000080
        8000008080000080800000000000000000000000000000000000000000000080
        8000008080000080800000808000008080000000000000000000000000000080
        8000008080000080800000808000008080000080800000808000000000000080
        8000008080000080800000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      OnDownClick = sbIncrementDownClick
      OnUpClick = sbIncrementUpClick
    end
    object edtColumnsNumber: TEdit
      Left = 60
      Top = 49
      Width = 60
      Height = 21
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      TabOrder = 4
      Text = '15'
      OnExit = edtColumnsNumberExit
    end
    object sbColumnsNumber: TCSpinButton
      Left = 137
      Top = 49
      Width = 15
      Height = 21
      DownGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000008080000080800000808000000000000080800000808000008080000080
        8000008080000080800000808000000000000000000000000000008080000080
        8000008080000080800000808000000000000000000000000000000000000000
        0000008080000080800000808000000000000000000000000000000000000000
        0000000000000000000000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      TabOrder = 5
      UpGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000000000000000000000000000000000000000000000000000000000000080
        8000008080000080800000000000000000000000000000000000000000000080
        8000008080000080800000808000008080000000000000000000000000000080
        8000008080000080800000808000008080000080800000808000000000000080
        8000008080000080800000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      OnDownClick = sbColumnsNumberDownClick
      OnUpClick = sbColumnsNumberUpClick
    end
    object cbMotorolaIntegerFormat: TCheckBox
      Left = 6
      Top = 104
      Width = 67
      Height = 15
      Alignment = taLeftJustify
      Caption = 'Motorola'
      TabOrder = 6
      OnClick = cbMotorolaIntegerFormatClick
      OnKeyUp = cbMotorolaIntegerFormatKeyUp
    end
    object edtPrecision: TEdit
      Left = 60
      Top = 71
      Width = 60
      Height = 21
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      ReadOnly = True
      TabOrder = 7
      Text = '2'
      OnExit = edtPrecisionExit
    end
    object sbPrecision: TCSpinButton
      Left = 137
      Top = 71
      Width = 15
      Height = 21
      DownGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000008080000080800000808000000000000080800000808000008080000080
        8000008080000080800000808000000000000000000000000000008080000080
        8000008080000080800000808000000000000000000000000000000000000000
        0000008080000080800000808000000000000000000000000000000000000000
        0000000000000000000000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      TabOrder = 8
      UpGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000000000000000000000000000000000000000000000000000000000000080
        8000008080000080800000000000000000000000000000000000000000000080
        8000008080000080800000808000008080000000000000000000000000000080
        8000008080000080800000808000008080000080800000808000000000000080
        8000008080000080800000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      OnDownClick = sbPrecisionDownClick
      OnUpClick = sbPrecisionUpClick
    end
    object cbSmall: TCheckBox
      Left = 6
      Top = 125
      Width = 67
      Height = 14
      Alignment = taLeftJustify
      Caption = 'Small'
      TabOrder = 9
      OnClick = cbSmallClick
      OnKeyUp = cbSmallKeyUp
    end
    object pnColorMin: TPanel
      Left = 18
      Top = 156
      Width = 30
      Height = 30
      Color = clYellow
      TabOrder = 10
      OnClick = pnColorMinClick
    end
    object pnColorMax: TPanel
      Left = 77
      Top = 156
      Width = 30
      Height = 30
      Color = clRed
      TabOrder = 11
      OnClick = pnColorMaxClick
    end
    object sbContrast: TScrollBar
      Left = 6
      Top = 218
      Width = 143
      Height = 16
      LargeChange = 10
      Min = 1
      PageSize = 0
      Position = 50
      TabOrder = 12
      OnChange = sbContrastChange
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 528
    Height = 420
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object PaintBox: TPaintBox
      Left = 0
      Top = 0
      Width = 512
      Height = 420
      Align = alClient
      OnClick = PaintBoxClick
      OnPaint = PaintBoxPaint
    end
    object sbPaintBox: TScrollBar
      Left = 512
      Top = 0
      Width = 16
      Height = 420
      Align = alRight
      Kind = sbVertical
      PageSize = 0
      TabOrder = 0
      OnChange = sbPaintBoxChange
    end
  end
  object MainMenu1: TMainMenu
    Left = 18
    Top = 13
    object miFile: TMenuItem
      Caption = 'Fichier'
      object miOpen: TMenuItem
        Caption = '&Ouvrir'
        OnClick = miOpenClick
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = 'Tous|*.*'
    Left = 50
    Top = 14
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Left = 577
    Top = 157
  end
end
