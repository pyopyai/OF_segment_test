# OF_segment_test

OpenFrameWorksの利用法と、オブジェクト指向をゲームプログラミングを通じて学びたい

現在構想中の「レーダーゲーム（仮）」の試作のため、線分の交差判定をここでテストします。（このレポジトリをそのまま本番開発につかうかも


## レーダーゲーム(仮)とは
中学のころにpyopyaiが発案したゲーム。実装が簡単そうなのでこれを初のゲームプログラミングの素材とする。

### ルール説明
#### 準備
1. A4の紙を用意する
1. A4の短辺を自分と対戦相手に向ける。
2. じゃんけん等で先攻後攻を決める。
### 対戦
A4の四隅の角は砲台である。手前側の2つの角、そして向こう側の2つの角はそれぞれ自分側と相手側の砲台である。
このゲームの目的は相手の砲台を２つとも全部破壊することである。
自分の砲台から発射したビームによって相手の砲台を破壊することができる。
ビームは自分の砲台、もしくはすでに発射したビームの先端から15cmの長さまで伸ばすことができる。
A4の長辺が29cm強なのでちょうど最短で二ターンで相手の砲台を破壊できることになる。
発射したビームはすでに盤面上に存在しているビームを横切ることで、自分のもの相手のものを問わず切断することができる。
切断されたビームは砲台から経路をたどることができる部分を残して消滅する。
さらに、切断されたビームは先端が他のビームで塞がれているため、そこからビームを伸ばすことができない。
