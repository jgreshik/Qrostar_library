VarIntS Summary_CrystalCount = 0;

void Init()
{
    Summary_CrystalCount = CountItem("Crystal");
    RemoveItem("Crystal", CountItem("Crystal"));

    Clothes_Active = 0;
    if (CheckPassedFlag("World1Done")) {
        goto World1Done;
    }

    if (CheckFlag("GuideA_Done")) {
        SetPos("Player", MarkerX("Machine"), MarkerY("Machine") + 2);
    }
}

void WallWall()
{
    > かべだ。;
}

void WallTank()
{
    > タンクのようだ。;
}

void WallComputer()
{
    > コンピューターだ。;
}

void World1Done()
{
    PlayMusic("Silence");
    SetPos("Player", MarkerX("Machine"), MarkerY("Machine") + 1);
    SetPos("Robo", MarkerX("Machine") - 1, MarkerY("Machine") + 1);
    SetPos("Doctor", MarkerX("Machine") + 1, MarkerY("Machine") + 1);
    Robo_Balloon = 0;
    Doctor_Balloon = 0;
    SetFacingRight("Robo", 1);
    SetFacingRight("Doctor", 0);
    
    PlaySe("WarpEnd");
    WarpEffect(0);
    
    SetThis("Doctor");
    > おお、かえってきた！;
    SetThis("Robo");
    > オカエリ！;
    
    SetThis("Doctor");
    if (Summary_CrystalCount == 0) {
        > 赤い結晶は…みつからなかったか。;
    } else if (Summary_CrystalCount == 1) {
        > 赤い結晶は#{Summary_CrystalCount}こみつかったか！;
        > すばらしい！;
    } else if (2 <= Summary_CrystalCount) {
        > すごい！赤い結晶を#{Summary_CrystalCount}こもみつけたのか！;
    }
    Wait(30);
    Player_Fainted = 1;
    PlaySe("Death");
    Wait(60);
    > おい、だいじょうぶか！;
    
    if (0 < Summary_CrystalCount) {
        FadeBlack(1);
        Wait(60);
        SetPos("Player", MarkerX("Bed"), MarkerY("Bed"));
        SetPos("Robo", MarkerX("Bed") + 5, MarkerY("Bed"));
        SetPos("Doctor", MarkerX("Bed") + 1, MarkerY("Bed"));
        SetFacingRight("Robo", 0);
        SetFacingRight("Doctor", 0);
        Player_Active = 0;
        BedPlayer_Angry = 1;
        Clothes_Active = 1;
        Wait(30);
        FadeBlack(0);
        PlayMusic("Clear");
        Wait(120);
        
        SetThis("Doctor");
        Walk("Doctor", 2, 0);
        Wait(1);
        > うん、だいじょうぶそうだ。;
        > やはりかなりつかれているみたいだ。;
        SetThis("Robo");
        > ブジデ ヨカッタ。;
        
        Walk("Doctor", 4, 0 - 1);
        Wait(1);
        SetThis("Robo");
        > ハカセ。;
        > カノジョハ ニンゲンジャナイノ？;
        SetThis("Doctor");
        > …。;
        > かのじょは ふつうの にんげんじゃない。;
        > とくべつなちが ながれているんだ。;
        > ふしぎなことに そのせいぶんは 赤い結晶に とてもにている…。;
        > そのちの おかげで 時空をいどうしても ぶじでいられる。;
        SetThis("Robo");
        > ナルホド。;
        SetThis("Doctor");
        > だから、かのじょは もとのせかいを とりもどす さいごのきぼうなんだ。;
        > 赤い結晶を あつめてもらわないと…。;
        Wait(1);
        Walk("Doctor", 0 + 1, 0);
        Wait(1);
        Walk("Doctor", 0 + 6, 0 - 20);
        
    }
    
    goto Summary;
}

void Summary()
{
    Wait(60);
    Summary();
    WaitSummaryDone();
    
    if (0 < Summary_CrystalCount) {
        goto AskPlayAgainCleared;
    } else {
        goto AskPlayAgain;
    }
}

void AskPlayAgain()
{
    MoveNext();
    MoveNextDone();
    Face("Rabi");
    Ask();
    > もういちどあそびますか？;
    if (Answer == 0) {
        FadeBlack(1);
        Wait(60);
        ClearItem();
        ChangeScene("01");
        return;
    } else {
        ChangeSceneTitle();
        return;
    }
}

void AskPlayAgainCleared()
{
    MoveNext();
    MoveNextDone();
    Face("Rabi");
    > このバージョンは これでおわりです！;
    if (5 <= Summary_CrystalCount) {
        Face("Rabi");
        > すべての 赤い結晶を あつめることが できたのですね！;
        Face("Rabi");
        > すばらしいです！;
        Face("Rabi");
        Ask();
        > もし ゲームの つづきが かんせいしたら ぜひ また あそんでほしいです。;
        if (Answer == 0) {
            Face("Rabi");
            > イェーイ！ うれしいです。;
            Face("Rabi");
            > それでは また おあいしましょう。;
        } else {
            PlayMusic("Silence");
            Face("Rabi");
            > え…。;
            FadeBlack(1);
            Wait(60);
            Summary_CrystalCount = 0;
            ResetSummary();
            Summary();
            FadeBlack(0);
            Wait(180);
            WaitSummaryDone();
            SetMsgBoxFace(21);
            Ask();
            > もちものを ひきついで もういちどあそびますか？;
            if (Answer == 0) {
                FadeBlack(1);
                Wait(60);
                PassItem();
                ChangeScene("01");
                return;
            }
            FadeBlack(1);
            Wait(60);
            ChangeSceneTitle();
            return;
        }
    } else {
        Face("Rabi");
        > あそんでくれて ありがとうございました。;
    }
    Face("Rabi");
    Ask();
    > クリアがめんを ほぞんしますか？;
    if (Answer == 0) {
        HideCursor(75);
        Wait(15);
        Screenshot();
        Wait(60);
    }
    Face("Rabi");
    Ask();
    > もちものを ひきついで もういちどあそびますか？;
    if (Answer == 0) {
        FadeBlack(1);
        Wait(60);
        PassItem();
        ChangeScene("01");
        return;
    } else {
        Face("Rabi");
        Ask();
        > タイトルに もどりますか？ (もちものは うしなわれます。);
        if (Answer == 0) {
            ChangeSceneTitle();
            return;
        } else {
            goto AskPlayAgainCleared;
        }
    }
}

VarIntS Doctor_Spoke = 0;
VarIntS Doctor_Year0 = 2;
VarIntS Doctor_Year1 = 0;
VarIntS Doctor_Year2 = 0;
VarIntS Doctor_Year3 = 0;
VarIntD Doctor_Hour = 21;

void Doctor()
{
    if (Doctor_Spoke == 0) {
        > おはよう。;
        > じゅんびはいい？;
        > ミッションを かくにんするよ。;
    Doctor_Explanation:
        > きみは #{Doctor_Year0}#{Doctor_Year1}#{Doctor_Year2}#{Doctor_Year3}年前に てんそうされる。;
        > そこで 赤い結晶を さがすんだ。;
        > #{Doctor_Hour}時間後に こちらにぎゃくてんそうする。;
        Ask();
        > いいね？;
        if (Answer == 1) {
            goto Doctor_Explanation;
        }
    }
    > よし、それじゃあ、左のそうちに 立ってくれ。;
    Doctor_Spoke = 1;
}

VarIntS Robo_Spoke = 0;

void Robo()
{
    if (Robo_Spoke == 0) {
        > オハヨウ！;
        > ケンコウジョウタイハ ドウカナ;
        > …チェックチュウ…;
        Wait(120);
        > OK. モンダイナイデス;
    }
    Robo_Spoke = 1;
    > イッテラッシャイ！ハカセガ マッテルヨ;
}

void SettingOffToPast()
{
    Robo_Balloon = 0;
    Doctor_Balloon = 0;
    Walk("Robo", 0 - 7, 0 - 4);
    Walk("Doctor", 0 - 1, 0);
    Wait(1);
    SetThis("Doctor");
    > ぶじで かえってくるんだよ。;
    Wait(30);
    SetThis("Robo");
    > テンソウカイシ！;
    Wait(30);
    PlaySe("Warp");
    WarpEffect(1);
    Wait(120);
    ChangeScene("01");
}

void Bed()
{
    > ベッドだ。;
}

void Door()
{
    Ask();
    > トビラをあけますか？;
    if (Answer == 0) {
        PlaySe("DoorOpen");
        Member("Active") = 0;
    }
}

