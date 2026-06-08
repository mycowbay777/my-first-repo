import time

def pet_accounting_game():
    print("========================================")
    print("   🐾 歡迎來到【電子寵物記帳本】 🐾")
    print("========================================")
    print("這週的生活費預算為 2000 元，請好好控制花費！")
    print("你的小寵物「波波」會根據你的記帳狀況改變心情喔！\n")

    # 第 2 堂課學到的「變數」
    budget = 80000
    pet_hp = 100
    pet_exp = 0

    # 第 2 堂課學到的「迴圈」
    while True:
        print("-" * 40)
        print(f"[狀態] 💰 剩餘預算: {budget} 元 | ❤️ 波波健康度: {pet_hp} | ⭐ 經驗值: {pet_exp}")

#破產或生病的條件判斷
        if budget <= 0:
            print("\n😱 破產了！波波餓到離家出走了... 挑戰失敗。")
            break
        if pet_hp <= 0:
            print("\n🏥 壓力太大，波波生病住院了... 請好好反省你的理財習慣。挑戰失敗。")
            break

        # 第 3 堂課學到的「輸入」
        action = input("\n請輸入這筆花費的金額 (輸入 0 結束記帳並離開): ")

        # 簡單的防呆機制，確保輸入的是數字
        if not action.isdigit():
            print("⚠️ 請輸入正確的數字！")
            continue

        expense = int(action)

        if expense == 0:
            print("\n保存紀錄中... 波波跟你說掰掰，下次見！")
            break

        reason = input("這筆錢花在哪裡了呢？(例如：午餐、飲料、網購): ")

        # 扣除預算
        budget -= expense
        print(f"\n📝 紀錄成功：花了 {expense} 元在「{reason}」。")

        # 核心邏輯：根據花費金額決定寵物的狀態
        if expense > 500:
            print("💸 天啊！單筆花費太大了，錢包大失血，波波覺得很有壓力，健康度下降！")
            pet_hp -= 30
        elif expense > 200:
            print("🤔 這筆花費還可以接受，波波提醒你要繼續保持喔。")
            pet_exp += 5
        else:
            print("✨ 完美的日常控制！波波覺得你很棒，開心地跳了起來！")
            pet_exp += 15

#執行程式
if __name__ == "__main__":
    pet_accounting_game()