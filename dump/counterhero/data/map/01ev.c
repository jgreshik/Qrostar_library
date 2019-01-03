VarIntS CrystalMusic = 0;

void Init()
{
    GuideA_Active = 0;
    GuideB_Active = 0;
    GuideC_Active = 0;

    CrystalMusic = 1 - CheckFlag("Crystal_Unlocked");
    Crystal_Active = CheckFlag("Crystal_Unlocked");
    Voice1_Done = CheckFlag("Crystal_Unlocked");
    Voice2_Done = Voice1_Done;
    Voice3_Done = Voice1_Done;

    ReflectVillagerNum(Villager_Num);
	
    if (Restarted == 0) {
        PlaySe("WarpEnd");
        WarpEffect(0);
    }
}

void Locked()
{
    if (0 < CountItem("Key")) {
        Ask();
        > まほうのカギをつかいますか？;

        if (Answer == 0) {
            Away();
            RemoveItem("Key", 1);
            PlaySe("DoorOpen");
        }
    } else {
        > カギがかかっている。;
    }
}

void Sparkle()
{
    > #{ItemText(Arg(0))}を みつけた！;
    AddItem(Arg(0),1);
    Away();
}

void GuideA()
{
    > こんにちは。;
    > ゲームを あそんでくれて ありがとうございます。;
    > そして なんども しなせてしまって すみません…。;
    > このゲームは なんどもやりなおして クリアに ちかづいていく。 そんな ゲームなのです…。;
    > さて。;
    > ゲームの あそびかたせつめいを ついかしました。;
    > がめんの 左下の <i kind="SmallBtn" subKind="4"/>ボタンから 見れます。;
    > それでは！;
    SetFlag("GuideA_Done");
    UnlockGuideMenu();
    Away();
    Efp("Smoke");
}

void GuideB()
{
    Efp("Smoke");
    GuideB_ValueA = 0;
    > じゃーん！;
    > こんにちは！;
    > しっていますか？ <i kind="SmallBtn" subKind="0"/>をおせば しぬ前にも もどることができます。;
    > くりかえしおせば けっこうもどせるので べんりです。;
    > ぜひ かつよう してね。;
    > ただし…;
    > あきらめるしかないことも よくあります。;
    > なやましいですね。;
    > さて！;
    > あたらしい あそびかたの せつめいを ついかしました！;
    > がめんの 左下の <i kind="SmallBtn" subKind="4"/>ボタンから 見れます。;
    > では！;
    SetFlag("GuideA_Done");
    SetFlag("GuideB_Done");
    UnlockGuideMenu();
    Away();
    Efp("Smoke");
}

void GuideC()
{
    > イェーイ！;
    > 赤い結晶を 見つけたようですね！;
    > 赤い結晶を 手にしたあなたは、 じゆうに すうじを いれかえられるようになりました。;
    > しかも かいすうは むせいげんです。;
    > くわしい せつめいは あそびかたに ついかしたので ぜひ見てください。;
    > ではでは！;
    SetFlag("GuideA_Done");
    SetFlag("GuideB_Done");
    SetFlag("GuideC_Done");
    UnlockGuideMenu();
    Away();
    Efp("Smoke");
}

VarIntS Rabi_Apple = 3;
VarIntS Rabi_Apple_Given = 1;
VarIntS Rabi_Apple_Done = 0;
VarIntS Rabi_Apple_Again = 1;
VarIntS Rabi_Again = 0;
VarIntS Rabi_Again_Done = 0;

void Rabi()
{
    if (Rabi_Sleeping) {
        SetMsgBoxFace(20);
        > Zzz...;
        return;
    }
	
    if (Rabi_Again_Done) {
        > そういえば、 少し前に 山のほうで 男の人を見たんだ。;
        > なにしてたんだろう。;
        return;
    }
	
    if (Rabi_Again) {
        > そういえば、 またリンゴ#{Rabi_Apple_Again}こ 見つけたんだけど、;
        Ask();
        > いる？;
        if (Answer == 0) {
            AddItem("Apple", Rabi_Apple_Again);
    	    > はい！;
            Rabi_Again_Done = 1;
            Balloon();
        } else {
            > ふーん。;
        }
        return;
    }

    if (Rabi_Finished) {
        > だっしゅつ！;
        > イェーイ！<dummy/>;
        return;
    }

    if (Rabi_Stone) {
        if (3 <= StoneWidth()) {
            if (0 < CountItem("Crystal")) {
                if (CheckFlag("Crystal_Unlocked") == 0) {
                    TutorialB();
                }
            }
    	}
	
        if (StoneWidth() < 2) {
            > この石は #{StoneWidth()}人で うごかせそうだ。;
        } else {
            > この石は #{StoneWidth()}人がかりでないと うごかせなさそうだ。;
        }
    	
        if (StoneWidth() < 2) {
        } else if (StoneWidth() == 2) {
            > いっしょにおそう。;
        } else {
            > こまったね…。;
            if (Voice1_Done == 0) {
                goto Voice1;
            }
        }
        return;
    }
    	
    if (Rabi_Started) {
        > 倉庫っていわれてるけど、 なんの倉庫なんだろうね。;
        return;
    }

    if (Rabi_Apple_Done) {
        Ask();
        > ところで 前に 会ったことある？;
        if (Answer == 0) {
            > そうだよね！;
        } else {
            > きのせいか…;
        }
        return;
    }
    
    > やあ、リンゴ#{Rabi_Apple}こ ひろったんだ。;
	
    Ask();
    > #{Rabi_Apple_Given}こいる？;

    if (Answer == 0) {
        if (Rabi_Apple < Rabi_Apple_Given) {
    	    > あれ、そんなに 持ってなかった。;
    	} else {
            AddItem("Apple", Rabi_Apple_Given);
    	    > はい！;
        }
        Rabi_Apple_Done = 1;
    	Balloon();
    } else {
        > そうか。;
    }
}

VarIntD Demon_Time = 9;

void VillagerScared()
{
    > 夜#{Demon_Time}時をすぎると 山からカイブツが おりてくるんだ;
    > あぁ、どうしよう…;
}

VarIntS VillagerStorehouse_Done = 0;

void VillagerStorehouse()
{
    if (VillagerStorehouse_Done) {
        goto VillagerStorehouse_Where;
    }
    > ぼくは 村から にげてきて ここにかくれてるんだ。;
    > 夜になると 村に カイブツが やってくるからね…。;
    > ところで、 倉庫のこと 知ってる？;
    > 倉庫には おたからが ねむっているんだ。;
    Ask();
    > ソードをくれたら 倉庫のカギのばしょを おしえてあげるよ。;
    if (Answer == 0) {
    	if (0 < CountItem("Sword")) {
            RemoveItem("Sword", 1);
            > ありがたい！;
        VillagerStorehouse_Where:
            > 倉庫のいりぐちの すぐ左の木に カギは かくしてあるんだ。;
            > じゆうにしていいよ。;
            VillagerStorehouse_Done = 1;
            SetFlag("SecretKey_Unlocked");
    	} else {
            > もってないじゃん！;
    	}
    } else {
    	> 倉庫…。;
    }
}

void VillagerStorehouse2()
{
    > わたしは しっている。;
    > 倉庫に 赤い結晶が あるんだ。;
    > それがあれば カイブツに かてるかもしれない…。;
    > でもカギが かかってて はいれないんだ。;
    > カギは どこにあるんだろうね。;
}

void VillagerElderly()
{
    > わたしは この村で 一番の ものしりだ。;
    Ask(_("赤い結晶"), _("カイブツ"), _("ドラゴン"), _("北のいえ"));
    > なにか 聞きたいことはあるかい？;
    if (Answer == 0) {
        > 赤い結晶が もたらす力は 手にしたものによって ちがうんだ。;
    	> ある人は 空をとべるようになり、;
    	> またある人は 火をふけるようになった。;
        > ときに きょうだいな 力をえるものもいる。;
    	> ふしぎな石だ。;
    } else if (Answer == 1) {
        > カイブツは #{Demon_Time}時を すぎたころに とつじょあらわれ 村のほうへ むかってくる。;
        > 村の左のかべが けずられているのは カイブツのしわざなんだ。;
        > カイブツの力は 日に日に ましていて、 いずれは この村に とうたつするだろう。;
        > あのカイブツも 赤い結晶を もっているのかもしれないな。;
    } else if (Answer == 2) {
        > ドラゴンは #{Dragon_FireFreq}ターンごとに 火をふくんだ;
        > そして 火は #{Dragon_FireLength}マスまで のびる;
    	> 横にしか 火をふかないから 上か下から こうげきするといい;
    } else if (Answer == 3) {
        > 北のいえには カギがかかっていたとおもう。;
    	> わかいせいねんが すんでいるんだが、 さいきんは あまり外にでてこないんだ。;
        > なんだか 村の人を さけているようだ。;
    }
}

void VillagerMerchant()
{
    Merchant(_("なにかほしいものある？"), "Apple", 5, "GreatApple", 15, "Arrow", 10, "Shield", 30, "Sword", 40, "DragonSword", 100);
    if (Answer == 0) {
        > まいどありー。;
    } else if (Answer == 1) {
        > #{Player_Money}Gしか持ってないじゃない！;
    } else if (Answer == 2) {
        > またね。;
    }
}

void VillagerEquip()
{
    > ぶきは そうびしないと いみないよ！;
}

VarIntS VillagerStones_Count = 9;
VarIntD VillagerStones_BombCount = 0;

void VillagerStones()
{
    if (VillagerStones_Count == StoneCount() && NineStones_Away == 0) {
        if (VillagerStones_Count != 0) {
            > 村から すこし下に おりたところに #{VillagerStones_Count}つの石が ならんでいたと思う。;
            > どうも あのあたりに たからものが あるらしいんだ。;
            SetFlag("NineStones_Unlocked");
            SetStoneCount(VillagerStones_Count);
            return;
        }
    }

    > ところで #{ItemText("Bomb")} もってる？;
    > #{ItemText("Bomb")}が あれば かたいかべも こわせるんだ。;
    VillagerStones_BombCount = CountItem("Bomb");
    if (3 <= VillagerStones_BombCount) {
        > #{VillagerStones_BombCount}こも もってる！ すごい！;
    } else if (1 <= VillagerStones_BombCount) {
        > #{VillagerStones_BombCount}こ もってるんだね。;
    } else {
        > もってないんだね。;
    }
    SetItemCount("Bomb", VillagerStones_BombCount);
}

VarIntS Villager_Num = 8;

void VillagerNum()
{
    > カイブツをおそれて、みんな村から にげていったんだ。;
    > もう村には、あと#{Villager_Num}人しかいない…;
    ReflectVillagerNum(Villager_Num);
}

VarIntS Wingman_Done = 0;
VarIntS Wingman_Count = 2;

void Wingman()
{
    if (Wingman_Done) {
        > 空を じゆうに とべたらな…。;
        return;
    }
	
    > 村からにげてきたんだけど、 そのとちゅうで 赤い石をひろったんだ。;
    > そうしたら！ なんと せなかに #{Wingman_Count}まいの はねがはえたんだ。;
    if (Wingman_Count == 2) {
        > そして なんと！ じゆうに 空を とべるようになったんだ！;
        Wingman_Angry = 1;
        return;
    } else if (Wingman_Count == 0) {
        > きれいなだけで なんでもない石だ。;
    } else {
        > じゃまで しょうがないんだ。 とぶことも できないし。;
    }
    > だから この赤い石 きみに あげるよ。;
    Wingman_Done = 1;
    Balloon();
    AddItem("Crystal", 1);
}

VarIntD VillagerKey_Price = 99;

void VillagerKey()
{
    > なんでもあけられる まほうのカギ ほしい？;
    Ask();
    > #{VillagerKey_Price}Gで 売ってあげるよ？;
    if (Answer == 0) {
        if (VillagerKey_Price <= Player_Money) {
            > まいどありー;
            Player_Money -= VillagerKey_Price;
            AddItem("Key", 1);
        } else {
            > おかねが たりないじゃん！;
        }
    } else {
        > またね！;
    }
}

VarIntS VillagerGuardian_Done = 0;

void VillagerGuardian()
{
    > わたしは この村を カイブツから守るために みはっているんだ。;
    if (Member("Attack") == 0) {
        > でも まったくたたかいに そなえてないんだ。;
    } else {
        > わたしは たたかいに そなえて #{Member("Attack")}年も くんれんしてきたんだ。;
    }
    if (Member("Attack") == 0) {
        > わたしには ムリだな。;
        if (VillagerGuardian_Done == 0) {
            > だから この#{ItemText("DragonSword")} きみに あげるよ。;
            AddItem("DragonSword", 1);
            VillagerGuardian_Done = 1;
        }
    } else {
        > けっして まけることはない！;
    }
}

VarIntS Thoma_Apple = 0;
VarIntS Thoma_Hated = 0;
VarIntS Thoma_Crystal = 0;
VarIntS Thoma_HaveCrystal = 0;

void Thoma()
{
    if (Thoma_Started) {
        > …。;
        return;
    }
    if (Thoma_HaveCrystal) {
        > あぁ…カイブツ…。;
        return;
    }
    if (Thoma_Crystal) {
        Thoma_HaveCrystal = 1;
        Ask();
        > 赤い結晶 見たことある？;
        if (Answer == 0) {
            Ask();
            > 持ってる？;
            if (Answer == 0) {
                Ask();
                > ちょうだい？;
                if (Answer == 0) {
                    if (0 < CountItem("Crystal")) {
                        RemoveItem("Crystal", 1);
                        Demon_Active = 1;
                        Away();
                        SetPos("Demon", Member("Pos_X"), Member("Pos_Y"));
                        Balloon();
                        return;
                    } else {
                        > そうやって みんな うそをつくんだ。;
                        Balloon();
                        return;
                    }
                }
            }
        }
        > ふーん。;
        Balloon();
        return;
    }
    if (Thoma_Hated) {
        Thoma_Crystal = 1;
        > 山で 赤い結晶を みつけたんだ。;
        > 力が みなぎって すごい…。;
        > 今は もってないよ。;
        Balloon();
        return;
    }
    if (Thoma_Apple) {
        > みんなに きらわれてる。;
        Thoma_Hated = 1;
        Balloon();
        return;
    }
    > …。;
    if (0 < CountItem("Apple")) {
        Ask();
        > リンゴちょうだい？;
        if (Answer == 0) {
            RemoveItem("Apple", 1);
            > ありがとう。;
            Thoma_Apple = 1;
            Balloon();
        } else {
            > …。;
        }
    }
}

void Hermit()
{
    Ask();
    > ノナの いいつたえを しってるかい？;
    if (Answer == 1) {
        > むかしむかし、 大きな赤い岩が 空にうかんでいた。;
        > 人びとの うんめいは すべて その岩によって さだめられていたんだ。;
        > めがみ「ノナ」は 人びとを その うんめいから かいほうするために、;
        > おのを 手にとり 赤い岩を うちくだいたんだ。;
        > そして くだけちった 赤い岩は せかい中に ちりぢりに なったんだ。;
        > ノナは 赤い岩の のろいにより 石となってしまった。;
        > しかし それからというもの、 人びとは じゆうに 生きられるようになった。;
        > そして ここにある せきぞうが 石になってしまったノナらしいんだ。;
        > そんな いいつたえだよ。;
    }
	
    > ほんとうかどうかは わからないけどね。;
}

void Statue()
{
    > リアルな せきぞうだ。;
}

void Dragon()
{
    > …。;
}

void Slime()
{
    > …。;
}

void SlimeRed()
{
    > …。;
}

void Demon()
{
    > …。;
}

VarIntS ColdWind = 0;

void ColdWind()
{
    LongUnproceedable();
    > つめたい 風が ふきはじめた…。;
}

void SecretKey()
{
    > #{ItemText("StorehouseKey")}を みつけた。;
    AddItem("StorehouseKey", 1);
    Away();
}

void StorehouseLocked()
{
    if (0 < CountItem("StorehouseKey")) {
        Ask();
    	> #{ItemText("StorehouseKey")}を つかいますか？;

        if (Answer == 0) {
            Away();
            RemoveItem("StorehouseKey", 1);
            PlaySe("DoorOpen");
        }
    } else {
        if (0 < CountItem("Key")) {
            Ask();
            > #{ItemText("Key")}を つかいますか？;

            if (Answer == 0) {
                Away();
                RemoveItem("Key", 1);
                PlaySe("DoorOpen");
            }
        } else {
            > カギがかかっている。;
        }
    }
}

void Stone()
{
    if (StoneMoveable()) {
        if (Member("Width") == 2) {
            SetMsgBoxFace("Rabi");
            > せーの！;
            
            PlaySe("Stone");
            StoneMove();
        } else {
            Ask();
            > うごかしますか？;
            if (Answer == 0) {
                PlaySe("Stone");
                StoneMove();
            }
        }
    } else {
        > おもくてうごかせない。;
    }
}

VarIntS BeforeTimeToReturn_Done = 0;
VarIntS TimeToReturn_Count = 0;

void BeforeTimeToReturn()
{
    LongUnproceedable();
    > どこからか こえが きこえる…;
    SetMsgBoxFace("Doctor");
    > きこえるか？ハカセだ。;
    SetMsgBoxFace("Doctor");
    > まもなくラボに てんそうする。;
    BeforeTimeToReturn_Done = 1;
    TimeToReturn_Count = 3;
}

void TimeToReturn()
{
    SetMsgBoxFace("Robo");
    > テンソウヲ カイシシマス。;
    Wait(60);
    PassFlag("World1Done");
    PassPlayerStatus();
    PassItem();
    PassRecord();
    ChangeScene("02");
}

VarIntS Voice1_Done = 0;
VarIntS Voice2_Done = 0;
VarIntS Voice3_Done = 0;

void Voice1()
{
    Wait(60);
    FadeBlack(1);
    Wait(20);
    FadeBlack(0);
    Wait(60);
    SetThis();
    > どこからか こえが 聞こえる…;
    > こっちへおいで…;
    Voice1_Done = 1;
}

void Voice2()
{
    LongUnproceedable();
    > おいで…;
    Voice2_Done = 1;
}

void Voice3()
{
    Voice3_Done = 1;
    LongUnproceedable();
    > こっちへおいで…;
    > おまえに 力を さずけよう…;
    Crystal_Active = 1;
}

void Crystal()
{
    Away();
    > 赤い結晶を みつけた！;
    if (CheckFlag("Crystal_Unlocked") == 0) {
        FadeBlack(1);
        Wait(60);
        FadeBlack(0);
        Wait(60);
        > とくべつな力を えた！;
    }
    AddItem("Crystal", 1);
    SetThis("Rabi");
    Balloon();
}

void Secret()
{
    > 赤い結晶を みつけた！;
    AddItem("Crystal", 1);
    Away();
}

void Pidgen()
{
    if (CheckFlag("Crystal_Unlocked") == 1) {
        > ああ、 ぼくは ここで カイブツを みるために まちぶせているんだ。;
        > だいじょうぶ。 すぐに にげるよ。;
        return;
    }

    Ask();
    > 倉庫のカギのばしょ おしえるよ？;
    if (Answer == 0) {
        > 倉庫のいりぐちの すぐ左の木に カギは あるらしいんだ。;
        > だいじな じょうほうだよ。;
        SetFlag("SecretKey_Unlocked");
    } else {
    	> ふーん。;
    }
}
