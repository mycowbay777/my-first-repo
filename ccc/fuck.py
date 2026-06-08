import tkinter as tk
from tkinter import messagebox
import csv

budget = 3000       # 剩餘預算
pet_hp = 100        # 寵物血量
pet_level = 1       # 寵物等級
expense_history = []  # 用來存記帳紀錄的清單


#按鈕按下去要執行的「功能」（第 3 堂課：函式 def 與條件判斷）

def add_expense():
    # 這裡必須宣告我們要修改全域變數 (上台解釋時說這是在拿外面的變數來用即可)
    global budget, pet_hp, pet_level

#拿到格子裡輸入的文字 (I/O 觀念)
    amount_str = amount_entry.get()
    item = item_entry.get().strip()

#防呆機制：沒輸入或不是數字就警告
    if not amount_str.isdigit() or not item:
        messagebox.showwarning("錯誤", "請輸入正確的項目和純數字金額！")
        return

    expense = int(amount_str) # 把文字變成整數

#扣除預算，並把紀錄存進清單
    budget = budget - expense
    expense_history.append([item, expense])

#核心邏輯：根據金額判斷寵物狀態 (If-Elif-Else 應用)
    if expense >= 500:
        pet_hp = pet_hp - 30
        avatar_label.config(text="(>﹏<)", fg="red")
        status_label.config(text=f"太奢侈了！花了 {expense} 元在「{item}」，波波大扣血！")
    elif expense <= 100:
        pet_level = pet_level + 1
        avatar_label.config(text="(^▽^)", fg="green")
        status_label.config(text=f"好省喔！花了 {expense} 元在「{item}」，波波升級了！")
    else:
        avatar_label.config(text="(=•̀ 〰 •́=)", fg="orange")
        status_label.config(text=f"成功紀錄：{item} 花了 {expense} 元。")

#清空格子，方便下一次輸入
    amount_entry.delete(0, tk.END)
    item_entry.delete(0, tk.END)
#更新畫面上的數字
    budget_label.config(text=f"💰 剩餘預算: {budget} 元")
    level_label.config(text=f"⭐ 寵物等級: Lv.{pet_level}")
    hp_label.config(text=f"❤️ 波波健康度: {pet_hp} / 100")

#檢查是否 Game Over
    if budget <= 0:
        messagebox.showerror("Game Over", "預算花光了！波波離家出走了...")
        window.quit()
    elif pet_hp <= 0:
        messagebox.showerror("Game Over", "波波壓力太大生病住院了！")
        window.quit()


#離開並存檔的功能 (第 5、6 堂課：CSV檔案輸出)

def save_and_exit():
    if expense_history:
        # 把清單寫入成 Excel 可以讀的 CSV 檔
        with open("bobo_expenses.csv", mode='w', newline='', encoding='utf-8-sig') as file:
            writer = csv.writer(file)
            writer.writerow(["花費項目", "金額"]) # 寫入標頭
            for row in expense_history:         # 寫入每一筆記帳
                writer.writerow(row)
        messagebox.showinfo("存檔成功", "記帳紀錄已匯出至 bobo_expenses.csv 檔！")
    window.quit()


#建立畫面的外殼 (Tkinter 基本視窗設定)

window = tk.Tk()
window.title("波波電子寵物記帳本")
window.geometry("400x450")

#畫面的元件 (Label 是文字，Entry 是輸入框，Button 是按鈕)
title_label = tk.Label(window, text="🐾 波波記帳本", font=("Arial", 20, "bold"))
title_label.pack(pady=10)

avatar_label = tk.Label(window, text="(=^･ω･^=)", font=("Arial", 36), fg="orange")
avatar_label.pack(pady=10)

status_label = tk.Label(window, text="狀態：波波今天心情很好！", font=("Arial", 12))
status_label.pack(pady=5)
#數據顯示
budget_label = tk.Label(window, text=f"💰 剩餘預算: {budget} 元", font=("Arial", 12, "bold"))
budget_label.pack(pady=5)

level_label = tk.Label(window, text=f"⭐ 寵物等級: Lv.{pet_level}", font=("Arial", 12))
level_label.pack(pady=5)

hp_label = tk.Label(window, text=f"❤️ 波波健康度: {pet_hp} / 100", font=("Arial", 12))
hp_label.pack(pady=5)

#輸入格子
tk.Label(window, text="金額:").pack()
amount_entry = tk.Entry(window)
amount_entry.pack()

tk.Label(window, text="項目:").pack()
item_entry = tk.Entry(window)
item_entry.pack()

#按鈕 (command 綁定上面寫好的功能)
submit_btn = tk.Button(window, text="確認記帳", command=add_expense, bg="lightgreen")
submit_btn.pack(pady=10)

exit_btn = tk.Button(window, text="💾 儲存並離開", command=save_and_exit, bg="lightblue")
exit_btn.pack(pady=10)

#讓視窗持續運作的迴圈
window.mainloop()