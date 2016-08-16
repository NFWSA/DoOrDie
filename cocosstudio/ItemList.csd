<GameFile>
  <PropertyGroup Name="ItemList" Type="Layer" ID="c79176e9-9563-4f4b-8e03-07b236cad60d" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="ItemList" Tag="15" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="itemList" ActionTag="-1472633872" Tag="84" IconVisible="False" LeftMargin="38.6000" RightMargin="671.4000" TopMargin="39.7100" BottomMargin="60.2900" TouchEnable="True" ClipAble="False" BackColorAlpha="102" ColorAngle="90.0000" ScrollDirectionType="0" DirectionType="Vertical" ctype="ListViewObjectData">
            <Size X="250.0000" Y="540.0000" />
            <AnchorPoint />
            <Position X="38.6000" Y="60.2900" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0402" Y="0.0942" />
            <PreSize X="0.2604" Y="0.8438" />
            <SingleColor A="255" R="150" G="150" B="255" />
            <FirstColor A="255" R="150" G="150" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="nameLabel" ActionTag="-773376265" Tag="27" IconVisible="False" LeftMargin="613.3028" RightMargin="250.6972" TopMargin="68.5232" BottomMargin="523.4768" FontSize="48" LabelText="名字" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="96.0000" Y="48.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="661.3028" Y="547.4768" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6889" Y="0.8554" />
            <PreSize X="0.1000" Y="0.0750" />
            <FontResource Type="Default" Path="" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="descLabel" ActionTag="2074328415" Tag="28" IconVisible="False" LeftMargin="333.6038" RightMargin="26.3962" TopMargin="236.3031" BottomMargin="53.6969" IsCustomSize="True" FontSize="36" LabelText="请选择一项物品..." ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="600.0000" Y="350.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="633.6038" Y="228.6969" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6600" Y="0.3573" />
            <PreSize X="0.6250" Y="0.5469" />
            <FontResource Type="Default" Path="" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="icon" ActionTag="516592756" Tag="222" IconVisible="False" LeftMargin="390.2971" RightMargin="523.7029" TopMargin="68.5231" BottomMargin="525.4769" ctype="SpriteObjectData">
            <Size X="46.0000" Y="46.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="413.2971" Y="548.4769" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4305" Y="0.8570" />
            <PreSize X="0.0479" Y="0.0719" />
            <FileData Type="Default" Path="Default/Sprite.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="btnList" ActionTag="-634428500" Tag="121" IconVisible="False" LeftMargin="833.6038" RightMargin="26.3962" TopMargin="68.5233" BottomMargin="451.4767" TouchEnable="True" ClipAble="False" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ScrollDirectionType="0" DirectionType="Vertical" ctype="ListViewObjectData">
            <Size X="100.0000" Y="120.0000" />
            <Children>
              <AbstractNodeData Name="useBtn" ActionTag="447773342" Tag="29" IconVisible="False" BottomMargin="60.0000" TouchEnable="True" FontSize="36" ButtonText="使用" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="50" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="50.0000" Y="90.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7500" />
                <PreSize X="1.0000" Y="0.5000" />
                <FontResource Type="Default" Path="" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Normal" Path="Data/UI/withcsb/button-item-disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Data/UI/withcsb/button-item-click.png" Plist="" />
                <NormalFileData Type="Normal" Path="Data/UI/withcsb/button-item-normal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="returnBtn" ActionTag="-965463913" ZOrder="1" Tag="7" IconVisible="False" TopMargin="60.0000" TouchEnable="True" FontSize="36" ButtonText="返回" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="50" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="50.0000" Y="30.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.2500" />
                <PreSize X="1.0000" Y="0.5000" />
                <FontResource Type="Default" Path="" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <DisabledFileData Type="Normal" Path="Data/UI/withcsb/button-item-disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Data/UI/withcsb/button-item-click.png" Plist="" />
                <NormalFileData Type="Normal" Path="Data/UI/withcsb/button-item-normal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="833.6038" Y="451.4767" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8683" Y="0.7054" />
            <PreSize X="0.1042" Y="0.1875" />
            <SingleColor A="255" R="150" G="150" B="255" />
            <FirstColor A="255" R="150" G="150" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>