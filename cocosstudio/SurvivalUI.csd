<GameFile>
  <PropertyGroup Name="SurvivalUI" Type="Layer" ID="0766ccdc-cb9d-44d8-ba33-9b54089d6ee0" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="SurvivalUI" Tag="15" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="picture" ActionTag="-816592502" Tag="64" IconVisible="False" LeftMargin="83.1800" RightMargin="830.8200" TopMargin="55.3100" BottomMargin="538.6900" ctype="SpriteObjectData">
            <Size X="46.0000" Y="46.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="106.1800" Y="561.6900" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1106" Y="0.8776" />
            <PreSize X="0.0479" Y="0.0719" />
            <FileData Type="Default" Path="Default/Sprite.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="dayLabGrp" ActionTag="-306566474" Tag="14" IconVisible="False" LeftMargin="757.3300" RightMargin="10.6700" TopMargin="35.9965" BottomMargin="556.0035" FontSize="48" LabelText="第    天" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="192.0000" Y="48.0000" />
            <Children>
              <AbstractNodeData Name="dayLabel" ActionTag="-1878624700" Tag="16" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="60.0000" RightMargin="60.0000" FontSize="48" LabelText="999" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="72.0000" Y="48.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="96.0000" Y="24.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.3750" Y="1.0000" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="853.3300" Y="580.0035" />
            <Scale ScaleX="0.9074" ScaleY="0.8499" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8889" Y="0.9063" />
            <PreSize X="0.2000" Y="0.0750" />
            <FontResource Type="Default" Path="" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="dayList" ActionTag="1648390968" Tag="18" IconVisible="False" LeftMargin="778.0500" RightMargin="31.9500" TopMargin="290.5600" BottomMargin="184.4400" ClipAble="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="0" DirectionType="Vertical" ctype="ListViewObjectData">
            <Size X="150.0000" Y="165.0000" />
            <Children>
              <AbstractNodeData Name="useItemBtn" ActionTag="-1560847756" Tag="23" IconVisible="False" BottomMargin="110.0000" TouchEnable="True" FontSize="36" ButtonText="使用道具" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="55.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="75.0000" Y="137.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8333" />
                <PreSize X="1.0000" Y="0.3333" />
                <FontResource Type="Normal" Path="Data/UI/withcsb/button-font.TTF" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Normal" Path="Data/UI/withcsb/button-disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Data/UI/withcsb/button-click.png" Plist="" />
                <NormalFileData Type="Normal" Path="Data/UI/withcsb/button-normal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="makeItemBtn" ActionTag="-1284452571" ZOrder="1" Tag="24" IconVisible="False" TopMargin="55.0000" BottomMargin="55.0000" TouchEnable="True" FontSize="36" ButtonText="制作物品" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="55.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="75.0000" Y="82.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="1.0000" Y="0.3333" />
                <FontResource Type="Normal" Path="Data/UI/withcsb/button-font.TTF" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Normal" Path="Data/UI/withcsb/button-disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Data/UI/withcsb/button-click.png" Plist="" />
                <NormalFileData Type="Normal" Path="Data/UI/withcsb/button-normal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="skipBtn" ActionTag="-698835183" ZOrder="2" Tag="30" IconVisible="False" TopMargin="110.0000" TouchEnable="True" FontSize="36" ButtonText="待  命" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="55.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="75.0000" Y="27.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1667" />
                <PreSize X="1.0000" Y="0.3333" />
                <FontResource Type="Normal" Path="Data/UI/withcsb/button-font.TTF" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Normal" Path="Data/UI/withcsb/button-disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Data/UI/withcsb/button-click.png" Plist="" />
                <NormalFileData Type="Normal" Path="Data/UI/withcsb/button-normal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="778.0500" Y="184.4400" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8105" Y="0.2882" />
            <PreSize X="0.1563" Y="0.2578" />
            <SingleColor A="255" R="150" G="150" B="255" />
            <FirstColor A="255" R="150" G="150" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="nightList" ActionTag="-2056750610" Tag="70" IconVisible="False" LeftMargin="778.0500" RightMargin="31.9500" TopMargin="290.5600" BottomMargin="239.4400" ClipAble="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="0" DirectionType="Vertical" ctype="ListViewObjectData">
            <Size X="150.0000" Y="110.0000" />
            <Children>
              <AbstractNodeData Name="sleepBtn" ActionTag="-446579225" Tag="73" IconVisible="False" BottomMargin="55.0000" TouchEnable="True" FontSize="36" ButtonText="全部休息" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="55.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="75.0000" Y="82.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7500" />
                <PreSize X="1.0000" Y="0.5000" />
                <FontResource Type="Normal" Path="Data/UI/withcsb/button-font.TTF" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Normal" Path="Data/UI/withcsb/button-disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Data/UI/withcsb/button-click.png" Plist="" />
                <NormalFileData Type="Normal" Path="Data/UI/withcsb/button-normal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="exploreBtn" ActionTag="460153708" ZOrder="1" Tag="74" IconVisible="False" TopMargin="55.0000" TouchEnable="True" FontSize="36" ButtonText="外出探险" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="28" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="150.0000" Y="55.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="75.0000" Y="27.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.2500" />
                <PreSize X="1.0000" Y="0.5000" />
                <FontResource Type="Normal" Path="Data/UI/withcsb/button-font.TTF" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Normal" Path="Data/UI/withcsb/button-disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Data/UI/withcsb/button-click.png" Plist="" />
                <NormalFileData Type="Normal" Path="Data/UI/withcsb/button-normal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="778.0500" Y="239.4400" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8105" Y="0.3741" />
            <PreSize X="0.1563" Y="0.1719" />
            <SingleColor A="255" R="150" G="150" B="255" />
            <FirstColor A="255" R="150" G="150" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="hpBar" ActionTag="-1391685145" Tag="17" IconVisible="False" LeftMargin="75.9774" RightMargin="774.0226" TopMargin="148.8943" BottomMargin="470.1057" ProgressInfo="100" ctype="LoadingBarObjectData">
            <Size X="110.0000" Y="21.0000" />
            <Children>
              <AbstractNodeData Name="hpLabel" ActionTag="174583606" Tag="147" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="50.0000" RightMargin="50.0000" TopMargin="0.5000" BottomMargin="0.5000" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="10.0000" Y="20.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="55.0000" Y="10.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.0909" Y="0.9524" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="130.9774" Y="480.6057" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="40" B="50" />
            <PrePosition X="0.1364" Y="0.7509" />
            <PreSize X="0.1146" Y="0.0328" />
            <ImageFileData Type="Normal" Path="Data/UI/withcsb/progressBar-better.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="spBar" ActionTag="1842274833" Tag="18" IconVisible="False" LeftMargin="75.9774" RightMargin="774.0226" TopMargin="172.2129" BottomMargin="446.7871" ctype="LoadingBarObjectData">
            <Size X="110.0000" Y="21.0000" />
            <Children>
              <AbstractNodeData Name="spLabel" ActionTag="694804874" Tag="149" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="50.0000" RightMargin="50.0000" TopMargin="0.5000" BottomMargin="0.5000" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="10.0000" Y="20.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="55.0000" Y="10.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.0909" Y="0.9524" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="130.9774" Y="457.2871" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1364" Y="0.7145" />
            <PreSize X="0.1146" Y="0.0328" />
            <ImageFileData Type="Normal" Path="Data/UI/withcsb/progressBar-better.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="satBar" ActionTag="-565143068" Tag="19" IconVisible="False" LeftMargin="75.9812" RightMargin="774.0188" TopMargin="194.7806" BottomMargin="424.2194" ctype="LoadingBarObjectData">
            <Size X="110.0000" Y="21.0000" />
            <Children>
              <AbstractNodeData Name="satLabel" ActionTag="1944015788" Tag="151" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="50.0000" RightMargin="50.0000" TopMargin="0.5000" BottomMargin="0.5000" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="10.0000" Y="20.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="55.0000" Y="10.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.0909" Y="0.9524" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5091" ScaleY="0.4844" />
            <Position X="131.9822" Y="434.3918" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="0" />
            <PrePosition X="0.1375" Y="0.6787" />
            <PreSize X="0.1146" Y="0.0328" />
            <ImageFileData Type="Normal" Path="Data/UI/withcsb/progressBar-better.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="vitBar" ActionTag="1965321877" Tag="20" IconVisible="False" LeftMargin="75.9774" RightMargin="774.0226" TopMargin="216.5931" BottomMargin="402.4069" ctype="LoadingBarObjectData">
            <Size X="110.0000" Y="21.0000" />
            <Children>
              <AbstractNodeData Name="vitLabel" ActionTag="468343176" Tag="150" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="50.0000" RightMargin="50.0000" TopMargin="0.5000" BottomMargin="0.5000" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="10.0000" Y="20.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="55.0000" Y="10.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.0909" Y="0.9524" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="130.9774" Y="412.9069" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="255" />
            <PrePosition X="0.1364" Y="0.6452" />
            <PreSize X="0.1146" Y="0.0328" />
            <ImageFileData Type="Normal" Path="Data/UI/withcsb/progressBar-better.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="hpLab" ActionTag="973887173" ZOrder="3" Tag="141" IconVisible="False" LeftMargin="27.0833" RightMargin="892.9167" TopMargin="148.8946" BottomMargin="471.1054" FontSize="20" LabelText="生命" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="40.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="47.0833" Y="481.1054" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0490" Y="0.7517" />
            <PreSize X="0.0417" Y="0.0313" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="spLab" ActionTag="1608756859" Tag="142" IconVisible="False" LeftMargin="27.0833" RightMargin="892.9167" TopMargin="172.2131" BottomMargin="447.7869" FontSize="20" LabelText="精神" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="40.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="47.0833" Y="457.7869" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0490" Y="0.7153" />
            <PreSize X="0.0417" Y="0.0313" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="satLab" ActionTag="-177997319" Tag="143" IconVisible="False" LeftMargin="27.0833" RightMargin="892.9167" TopMargin="194.7808" BottomMargin="425.2192" FontSize="20" LabelText="饱食" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="40.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="47.0833" Y="435.2192" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0490" Y="0.6800" />
            <PreSize X="0.0417" Y="0.0313" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="vitLab" ActionTag="1914172955" Tag="144" IconVisible="False" LeftMargin="27.0833" RightMargin="892.9167" TopMargin="216.5933" BottomMargin="403.4067" FontSize="20" LabelText="体力" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="40.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="47.0833" Y="413.4067" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0490" Y="0.6459" />
            <PreSize X="0.0417" Y="0.0313" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="timesLabGrp" ActionTag="-1499609074" Tag="152" IconVisible="False" LeftMargin="781.3300" RightMargin="34.6700" TopMargin="94.5919" BottomMargin="521.4081" FontSize="24" LabelText="剩余行动  次" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="144.0000" Y="24.0000" />
            <Children>
              <AbstractNodeData Name="timesLabel" ActionTag="-156761167" Tag="153" IconVisible="False" LeftMargin="96.0000" RightMargin="24.0000" FontSize="24" LabelText="99" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="24.0000" Y="24.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="108.0000" Y="12.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7500" Y="0.5000" />
                <PreSize X="0.1667" Y="1.0000" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="853.3300" Y="533.4081" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8889" Y="0.8335" />
            <PreSize X="0.1500" Y="0.0375" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="pauseBtn" ActionTag="-57968915" Tag="44" IconVisible="False" LeftMargin="64.0399" RightMargin="799.9601" TopMargin="563.0959" BottomMargin="44.9041" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="66" Scale9Height="10" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="96.0000" Y="32.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="112.0399" Y="60.9041" />
            <Scale ScaleX="1.4023" ScaleY="1.4023" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1167" Y="0.0952" />
            <PreSize X="0.1000" Y="0.0500" />
            <TextColor A="255" R="65" G="65" B="70" />
            <PressedFileData Type="Normal" Path="Data/UI/Button/Pause_Click.png" Plist="" />
            <NormalFileData Type="Normal" Path="Data/UI/Button/Pause.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>