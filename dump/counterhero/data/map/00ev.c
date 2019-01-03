void Crystal_Desc()
{
    > 手にしたものに とくべつな力を あたえると いわれている ふしぎな石。;
}

void Key_Desc()
{
    > なんでも あけられる ハイテクなカギ。;
    > ただし つかいすて。;
}

void Apple()
{
    > HPが#{Apple_Value}かいふくした!;
    RestoreHp("Player", Apple_Value);
}

void Apple_Desc()
{
    > あかくて あまくて けんこうにいい くだもの。;
    > HPが#{Apple_Value}かいふくする。;
}

void GreatApple()
{
    > HPが#{GreatApple_Value}かいふくした!;
    RestoreHp("Player", GreatApple_Value);
}

void GreatApple_Desc()
{
    > じょうひんな あじわいの レアなリンゴ。;
    > HPが#{GreatApple_Value}かいふくする。;
}

void Shield_Desc()
{
    > かるくて じょうぶな いいそざいの たて。;
    > まもりが #{Shield_Value}ふえる。;
}

void Sword_Desc()
{
    > 手にすれば なんだか じしんも わいてくる。;
    > こうげきが #{Sword_Value}ふえる。;
}

void DragonSword_Desc()
{
    > こうげきが #{DragonSword_Value}ふえる。;
    > ふりおろせば ドラゴンのように 火をふく。;
}

void Skateboard_Desc()
{
    > いたに しゃりんが ついたもの。;
    > よこいどうが #{Skateboard_Value}ばいになる。;
}

void Watch()
{
    > いま#{Time_Hour}:#{Time_Minute as Zp}。;
}

void Watch_Desc()
{
    > げんざいの時間を 数字でおしえてくれる。;
    > アナログなほうが ちょっかんてきという 人もいる。;
}

void Arrow_Desc()
{
    > 遠くから こうげきできて つよい。;
    > #{Arrow_Value}マスさきまで とぶ。;
}

VarIntS Bomb_Turn = 3;

void Bomb_Desc()
{
    > #{Bomb_Turn}ターン後に ばくはつ。;
    > かべもこわせる。 とりあつかいちゅうい。;
}

VarIntS CobwebBall_Turn = 3;

void CobwebBall_Desc()
{
    > じんこうてきな くものすが あらわれる。;
    > #{CobwebBall_Turn}ターン てきを うごけなくする。;
}

void PSTester()
{
    > HP: #{Member("Hp")}/#{Member("MaxHp")} こうげき: #{Member("Attack")}、まもり: #{Member("Defense")};
}

void PSTester_NoOne()
{
    > そのほうこうには だれもいない。;
}

void PSTester_Desc()
{
    > てきの のうりょくを しらべることが できる すごいきかい。;
    > ただし しらべるためには しきんきょりに 近づく ひつようがある。;
}

VarIntD WoodTester_Count = 0;

void WoodTester()
{
    WoodTester_Count = WoodCount();
    > しゅうへんに #{WoodTester_Count}本の 木があります。;
    SetWoodCount(WoodTester_Count);
}

void WoodTester_Desc()
{
    > しゅうへんの 木のかずを かぞえることができる なぞのきかい。;
    > だれが なんのために 作ったのだろう…。;
}

void GustGenerator_Desc()
{
    > 空気に ショックをあたえ、 とっぷうを はっせいさせる すごいそうち。;
    > みんなを#{GustGenerator_Value}マス うごかす。;
}

VarIntS ElecBall_Life = 3;

void ElecBall_Desc()
{
    > せっちしたばしょで ほうでん。;
    > #{ElecBall_Life}かい あたるときえる。;
}

void Gps()
{
    > よこ#{Player_Pos_X as Zp} たて#{Player_Pos_Y as Zp} のばしょにいます。;
    CoolOff("Player");
}

void Gps_Desc()
{
    > GPSとは グリッド・ポイント・スペクテータの りゃく。;
    > 自分の いちを 知ることができる。;
}

void StorehouseKey_Desc()
{
    > 倉庫を あけるための カギ。;
}

void Chara_Damaged()
{
    if (IsPlayer()) {
        > #{Member("Damage")}のダメージをうけた。;
    } else {
        > #{Member("Damage")}のダメージをあたえた。;
    }
}

VarIntD Player_ExpEarned = 0;
VarIntD Player_MoneyEarned = 0;

void Player_Earned()
{
    > #{Player_MoneyEarned}Gと#{Player_ExpEarned}EXPをかくとくした。;
    Player_Exp += Player_ExpEarned;
    Player_ExpEarned = 0;
    Player_Money += Player_MoneyEarned;
    Player_MoneyEarned = 0;
}

VarIntS Player_AttackInc = 0;
VarIntS Player_DefenseInc = 0;
VarIntS Player_HpInc = 0;

void Player_LvUp()
{
    > レベルが#{Player_Lv}にあがった！;
    Player_AttackInc = AttackInc(Player_Lv);
    Player_DefenseInc = DefenseInc(Player_Lv);
    Player_HpInc = HpInc(Player_Lv);
    if (0 < Player_AttackInc) {
        > こうげき+#{Player_AttackInc}、さいだいHP+#{Player_HpInc};
    } else if (0 < Player_DefenseInc) {
        > まもり+#{Player_DefenseInc}、さいだいHP+#{Player_HpInc};
    } else {
        > さいだいHP+#{Player_HpInc};
    }
    
    Player_Attack += Player_AttackInc;
    Player_Defense += Player_DefenseInc;
    Player_MaxHp += Player_HpInc;
    
    Player_Hp = Player_MaxHp;
    
    Player_AttackInc = 0;
    Player_DefenseInc = 0;
    Player_HpInc = 0;
}

VarIntD ItemFound_Kind = 0;

void ItemFound()
{
    > #{ItemText(ItemFound_Kind)}を みつけた！;
    AddItem(ItemName(ItemFound_Kind),1);
}

void ItemDiscarded()
{
    > もちものが いっぱいで はいらなかった。;
}

VarIntD MoneyFound_Money = 10;

void MoneyFound()
{
    > #{MoneyFound_Money}Gを みつけた！;
    PlaySe("ItemFound");
    Player_Money += MoneyFound_Money;
}

void Chest()
{
    PlaySe("ChestOpen");
    Efp("RisingSparkle");
    Wait(10);
    PlaySe("RisingSparkle");
    ItemFound_Kind = Member("ValueB");
    Away();
    goto ItemFound;
}

void LockedChest()
{
    if (0 < CountItem("Key")) {
        Ask();
        > まほうのカギを つかいますか？;

        if (Answer == 0) {
            PlaySe("ChestOpen");
            Efp("RisingSparkle");
            Wait(10);
            PlaySe("RisingSparkle");
            ItemFound_Kind = Member("ValueB");
            Away();
            RemoveItem("Key", 1);
            goto ItemFound;
        }
    } else {
        > カギがかかっている。;
    }
}

VarIntS Error_Thrown = 0;
VarIntD Error_Code = 0;

void Error()
{
    > FATAL ERROR (#{Error_Code});
    RandomizeEverything();
}
