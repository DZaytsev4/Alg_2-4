#include "..//gtest/gtest-all.cc"
#include "..//priority_queue/priority_queue.h"
#include "..//skip_list/skip_list.h"
TEST(SkipListTest, InsertAndSearch) {
    SkipList<int> skipList;
    skipList.insert(10);
    skipList.insert(20);
    skipList.insert(30);

    ASSERT_TRUE(skipList.search(10));
    ASSERT_TRUE(skipList.search(20));
    ASSERT_TRUE(skipList.search(30));
    ASSERT_FALSE(skipList.search(15));
    ASSERT_FALSE(skipList.search(25));
}

TEST(SkipListTest, Remove) {
    SkipList<int> skipList;
    skipList.insert(10);
    skipList.insert(20);
    skipList.insert(30);
    skipList.remove(20);

    ASSERT_TRUE(skipList.search(10));
    ASSERT_FALSE(skipList.search(20));
    ASSERT_TRUE(skipList.search(30));
}

TEST(SkipListTest, ClearAndIsEmpty) {
    SkipList<int> skipList;
    skipList.insert(10);
    skipList.insert(20);
    skipList.insert(30);
    skipList.clear();

    ASSERT_TRUE(skipList.isEmpty());
    ASSERT_FALSE(skipList.search(10));
    ASSERT_FALSE(skipList.search(20));
    ASSERT_FALSE(skipList.search(30));
}
TEST(PriorityQueueTest, InsertAndPop) {
    Priority_queue<int> pq;
    pq.insert(10, 3);
    pq.insert(20, 2);
    pq.insert(30, 1);

    ASSERT_FALSE(pq.isEmpty());
    ASSERT_EQ(pq.pop().item, 10);
    ASSERT_EQ(pq.pop().item, 20);
    ASSERT_EQ(pq.pop().item, 30);
    ASSERT_TRUE(pq.isEmpty());
}

TEST(PriorityQueueTest, InsertAndPrint) {
    Priority_queue<int> pq;
    pq.insert(10, 3);
    pq.insert(20, 2);
    pq.insert(30, 1);

    testing::internal::CaptureStdout();
    std::cout << pq;
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "Element: 30, Priority: 1\nElement: 20, Priority: 2\nElement: 10, Priority: 3\n");
}