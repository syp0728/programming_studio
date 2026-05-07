# GenAI 관리 시스템 (CRUD Project)

이 프로젝트는 자바(Java)를 이용해 다양한 **생성형 AI(Generative AI) 서비스의 정보를 관리**하는 콘솔 기반 CRUD 프로그램입니다.
인터페이스(Interface)를 활용하여 설계되었으며, 데이터의 추가, 수정, 삭제뿐만 아니라 정렬 및 가격 비교 기능을 제공합니다.

---

## 주요 기능

1. **데이터 관리 (CRUD)**
    - **Add**: AI 서비스 이름, 개발사, 출시 연도, 카테고리, 구독 가격 등을 입력받아 저장합니다.
    - **List**: 저장된 모든 AI 정보를 번호와 함께 테이블 형식으로 출력합니다.
    - **Update**: 특정 번호의 데이터를 선택하여 상세 정보를 수정합니다.
    - **Delete**: 리스트에서 특정 데이터를 삭제합니다.

2. **부가 기능**
    - **Sort by Name**: AI 이름을 기준으로 오름차순 정렬합니다.
    - **Sort by Price**: 구독 가격이 낮은 순서대로 정렬합니다.
    - **Compare Price**: 두 개의 AI를 선택하여 가격을 비교하고 더 저렴한 서비스를 안내합니다.

---

## 📂 프로젝트 구조

| 파일명 | 경로 | 설명 |
| :--- | :--- | :--- |
| **Main.java** | `src/org/example/Main.java` | 프로그램 실행 및 메뉴 제어 (Loop) |
| **ICRUD.java** | `src/org/example/ICRUD.java` | CRUD 기능을 위한 표준 인터페이스 |
| **GenAI.java** | `src/org/example/GenAI.java` | AI 정보 객체를 정의한 모델 클래스 |
| **GenAICRUD.java** | `src/org/example/GenAICRUD.java` | 인터페이스를 구현한 실제 비즈니스 로직 |

---

## 에이전트 카테고리 가이드

프로그램에서 카테고리 입력 시 아래 코드를 사용하며, 출력 시 자동으로 변환됩니다.
- **B**: Chatbot (챗봇)
- **C**: Coding (코딩 도구)
- **I**: Image (이미지 생성)
- **R**: Research (연구/분석)
- **S**: Slide (프레젠테이션)

---

## 실행 화면 예시

```text
1. Add 2. List 3. Update 4. Delete 5. Sort by AIName 6. Sort by Price 7. Compare Price 0. Quit > 2
Total: 3
No      AI_Name         Company         Year    Agent_Type      Price   Created_Date
1       ChatGPT         OpenAI          2023    Chatbot         20.00   2022
2       Gemini          Google          2024    Coding          0.00    2023
3       Midjourney      Midjourney      2022    Image           30.00   2022