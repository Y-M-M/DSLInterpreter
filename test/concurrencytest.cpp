/**
 * @file concurrencytest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief 5 threads concurrency
 * @version 0.1
 * @date 2024-12-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include "pharser.h"

void run_carryout_in_thread(std::unique_ptr<Pharser> pharser, std::istringstream &input_stream, std::ostringstream &output_stream)
{
    std::cin.rdbuf(input_stream.rdbuf());   // 设置输入流
    std::cout.rdbuf(output_stream.rdbuf()); // 捕获输出流
    testing::internal::CaptureStdout();
    pharser->carryout(); // 执行 carryout
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Hello! Please input your username:\nWaiting time too long... disconnected, please log in again if necessary.\n", output);
}

TEST(ConcurrecncyTest, concurrency)
{
    istringstream input("../scripts/deposit.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    bool buildsucceed = pharser.build();
    EXPECT_EQ(true, pharser.check_issucceed());
    EXPECT_EQ(true, pharser.checkit());
    const int num_threads = 5; // 启动 5 个线程并发执行
    vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i)
    {
        threads.emplace_back([&pharser]()
                             { pharser.carryout(); });
    }
    for (auto &t : threads) // 等待线程完成
    {
        t.join();
    }
}