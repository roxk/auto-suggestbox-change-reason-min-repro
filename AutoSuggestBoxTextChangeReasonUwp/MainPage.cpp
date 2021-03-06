﻿#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <chrono>

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace std::chrono_literals;

namespace winrt::AutoSuggestBoxTextChangeReasonUwp::implementation
{
    MainPage::MainPage() : mSuggestions { single_threaded_observable_vector<IInspectable>() }, mSuggestionWithoutToStrings {single_threaded_observable_vector<IInspectable>()}
    {
        InitializeComponent();
    }
}

void winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::AutoSuggestBox_TextChanged(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args)
{
    if (args.Reason() == Windows::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason::UserInput)
    {
        UpdateSuggestions(sender.Text());
        auto debugText = L"Updating " + sender.Text() + L"\n";
        OutputDebugString(debugText.c_str());
    }
}

void winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::AutoSuggestBox_SuggestionChosen(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args)
{
    // If we comment out L"Custom display text", TextChanged would not report reason as UserInput.
    sender.Text(args.SelectedItem().as<AutoSuggestBoxTextChangeReasonUwp::SuggestionViewModel>().ToString() + L" and text set through suggestion chosen");
}

void winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::AutoSuggestBox_QuerySubmitted(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args)
{
}

Windows::Foundation::IAsyncAction winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::UpdateSuggestions(hstring query)
{
    apartment_context uiThread;
    co_await resume_background();
    // Pretend we are fetching things from the network
    co_await 500ms;
    co_await uiThread;
    mSuggestions.Clear();
    mSuggestions.Append(make<implementation::SuggestionViewModel>(query + L" A"));
    mSuggestions.Append(make<implementation::SuggestionViewModel>(query + L" B"));
}

void winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::AutoSuggestBox_TextChanged_Without_ToString(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs const& args)
{
    if (args.Reason() == Windows::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason::UserInput)
    {
        UpdateSuggestionWithoutToStrings(sender.Text());
        auto debugText = L"Updating " + sender.Text() + L"\n";
        OutputDebugString(debugText.c_str());
    }
}

void winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::AutoSuggestBox_SuggestionChosen_Without_ToString(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args)
{
    sender.Text(args.SelectedItem().as<AutoSuggestBoxTextChangeReasonUwp::SuggestionViewModelWithoutToString>().DisplayName());
}

void winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::AutoSuggestBox_QuerySubmitted_Without_ToString(winrt::Windows::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs const& args)
{
}

Windows::Foundation::IAsyncAction winrt::AutoSuggestBoxTextChangeReasonUwp::implementation::MainPage::UpdateSuggestionWithoutToStrings(hstring query)
{
    apartment_context uiThread;
    co_await resume_background();
    // Pretend we are fetching things from the network
    co_await 500ms;
    co_await uiThread;
    mSuggestions.Clear();
    mSuggestions.Append(make<implementation::SuggestionViewModelWithoutToString>(query + L" A"));
    mSuggestions.Append(make<implementation::SuggestionViewModelWithoutToString>(query + L" B"));
}